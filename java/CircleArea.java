public class CircleArea {

	public static void main(String[] args) { //현재 코드에선 string[] args가 필요 없으나 java 자체에서 string[] args가 들어가야만 main의 자리로 인정
		//main을 사용할 때 무조건 public static void main의 구성을 갖춰야만 java에서 인정해준다. 
		// TODO Auto-generated method stub
		//원의 넓이와 둘레의 길이
		final double PI = 3.14; //final이 앞에 들어가면 상수가 된다
    //PI의 값은 변경 불가능, 아래에서 다시 선언하면 오류가 발생한다
    
		double r = 10.0; // 원의 반지름
    //변수로 선언했기에 아래에 r=1.0따위의 줄을 추가해도 변경이 가능하다 
		
		double circleArea = r*r*PI; //변수 이름은 소문자로 시작하는 게 좋음
		
		System.out.println("원의 면적 =" + circleArea); //print에 있어 타입 지정이 필요 없다. 
		//System: 자바가 기본으로 제공하는 클래스, 컴퓨터 시스템 관련 기능 모아둠
		//out: 출력
		//System.out: 'System'안의 출력 창

	}

}
