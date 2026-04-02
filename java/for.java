public class Main {
    public static void main(String[] args) {

        int result = 0;

        for (int i = 0; i <= 10; i++) {
            result = result + i;
            System.out.print(i);

            if(i<10){System.out.print("+");}
                //조건문을 이용해 10인 상황이 오면 10인 상황이 오면 +를 사용하지 않게 바꿔주자
        }
        System.out.print("=" + result);
    }
}
