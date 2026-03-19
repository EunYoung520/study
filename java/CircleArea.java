public class CircleArea {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//원의 넓이와 둘레의 길이
		final double PI = 3.14; //final이 앞에 들어가면 상수가 된다
    //PI의 값은 변경 불가능, 아래에서 다시 선언하면 오류가 발생한다
    
		double r = 10.0; // 원의 반지름
    //변수로 선언했기에 아래에 r=1.0따위의 줄을 추가해도 변경이 가능하다 
		
		double CircleArea = r*r*PI; 
		
		System.out.println("원의 면적 =" + CircleArea); //print에 있어 타입 지정이 필요 없다. 

	}

}
