public class PrimitiveExample {
    public static void modifyValue(int num, int[] arr) {
        num = 100; // only changes number inside this modifier
        System.out.println("Inside modifier num == "+ num);
        arr[0] = 42; // this will change the array
        System.out.println("Inside modifier num == "+ arr[0]);
    }

    public static void main(String[] args) {
        int number = 1;
        int[] numbers = {1, 2, 3};
        modifyValue(number, numbers);
        System.out.println("outside modifier num == "+ number);
        System.out.println("outside modifier numbers == "+ numbers[0]);
        
    }
}
