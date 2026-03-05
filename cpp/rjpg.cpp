#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <jpeglib.h>
#include <png.h>
#include <stdlib.h>

// 전역 변수
JSAMPLE* g_img_jpg = NULL;
JSAMPLE* g_img_png = NULL;
int g_w_jpg = 0, g_h_jpg = 0, g_ch_jpg = 0;
int g_w_png = 0, g_h_png = 0, g_ch_png = 0;

// JPEG 읽기 함수
JSAMPLE* read_jpeg(const char* fname, int* w, int* h, int* ch) {
    FILE* in = fopen(fname, "rb");
    if (!in) {
        MessageBoxW(NULL, L"JPEG 파일을 열 수 없습니다.", L"오류", MB_ICONERROR);
        return NULL;
    }

    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    JSAMPLE* img;

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, in);

    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    *w = cinfo.output_width;
    *h = cinfo.output_height;
    *ch = cinfo.output_components;

    img = (JSAMPLE*)malloc((*w) * (*h) * (*ch));

    while (cinfo.output_scanline < *h) {
        JSAMPLE* row = img + cinfo.output_scanline * (*w) * (*ch);
        jpeg_read_scanlines(&cinfo, &row, 1);
    }

    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    fclose(in);

    return img;
}

// PNG 읽기 함수
JSAMPLE* read_png(const char* fname, int* w, int* h, int* ch) {
    FILE* in = fopen(fname, "rb");
    if (!in) {
        MessageBoxW(NULL, L"PNG 파일을 열 수 없습니다.", L"오류", MB_ICONERROR);
        return NULL;
    }

    png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png_ptr) {
        fclose(in);
        return NULL;
    }

    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr) {
        png_destroy_read_struct(&png_ptr, NULL, NULL);
        fclose(in);
        return NULL;
    }

    if (setjmp(png_jmpbuf(png_ptr))) {
        png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
        fclose(in);
        return NULL;
    }

    png_init_io(png_ptr, in);
    png_read_info(png_ptr, info_ptr);

    *w = png_get_image_width(png_ptr, info_ptr);
    *h = png_get_image_height(png_ptr, info_ptr);
    *ch = png_get_channels(png_ptr, info_ptr);

    png_bytep* row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * (*h));
    for (int y = 0; y < *h; y++) {
        row_pointers[y] = (png_byte*)malloc(png_get_rowbytes(png_ptr, info_ptr));
    }

    png_read_image(png_ptr, row_pointers);

    JSAMPLE* img = (JSAMPLE*)malloc((*w) * (*h) * (*ch));
    for (int y = 0; y < *h; y++) {
        memcpy(img + y * (*w) * (*ch), row_pointers[y], (*w) * (*ch));
        free(row_pointers[y]);
    }
    free(row_pointers);

    png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
    fclose(in);

    return img;
}

// 윈도우 프로시저 함수
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // JPG 이미지 그리기
        if (g_img_jpg)
        {
            for (int y = 0; y < g_h_jpg; y++)
            {
                for (int x = 0; x < g_w_jpg; x++)
                {
                    int index = (y * g_w_jpg + x) * g_ch_jpg;
                    SetPixel(hdc, x, y, RGB(g_img_jpg[index], g_img_jpg[index + 1], g_img_jpg[index + 2]));
                }
            }
        }

        // PNG 이미지 그리기
        if (g_img_png)
        {
            for (int y = 0; y < g_h_png; y++)
            {
                for (int x = 0; x < g_w_png; x++)
                {
                    int index = (y * g_w_png + x) * g_ch_png;
                    SetPixel(hdc, x + g_w_jpg + 10, y, RGB(g_img_png[index], g_img_png[index + 1], g_img_png[index + 2]));
                }
            }
        }

        EndPaint(hwnd, &ps);
        return 0;
    }
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// WinMain 함수
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // 윈도우 클래스 등록
    const wchar_t CLASS_NAME[] = L"Image Viewer Window Class";

    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // 이미지 로드
    g_img_jpg = read_jpeg("jcshim.jpg", &g_w_jpg, &g_h_jpg, &g_ch_jpg);
    if (!g_img_jpg) {
        MessageBoxW(NULL, L"JPEG 이미지 로드 실패", L"오류", MB_ICONERROR);
    }

    g_img_png = read_png("jcshim.png", &g_w_png, &g_h_png, &g_ch_png);
    if (!g_img_png) {
        MessageBoxW(NULL, L"PNG 이미지 로드 실패", L"오류", MB_ICONERROR);
    }

    if (!g_img_jpg && !g_img_png) {
        MessageBoxW(NULL, L"모든 이미지 로드 실패", L"오류", MB_ICONERROR);
        return 1;
    }

    // 윈도우 생성
    int total_width = g_w_jpg + g_w_png + 10; // 10픽셀 간격 추가
    int max_height = (g_h_jpg > g_h_png) ? g_h_jpg : g_h_png;

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        L"Image Viewer",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, total_width + 20, max_height + 40, // 여백 추가
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (hwnd == NULL) {
        MessageBoxW(NULL, L"윈도우 생성 실패", L"오류", MB_ICONERROR);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // 메시지 루프
    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // 메모리 해제
    free(g_img_jpg);
    free(g_img_png);

    return 0;
}