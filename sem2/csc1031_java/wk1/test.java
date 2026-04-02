public class test {
    public static void main(String[] args) {
        car bmw = new car();
        car bmw2 = new car();
        car bmw3 = new car();
        bmw.num_pl = "E3456";
        engine v12 = new engine();
        v12.hp = 120;
        bmw.e = v12;
        bmw2.e = v12;
        bmw.run();
    }

}
// 3 separate classes
// this defaults to public if you don't mention which it is.
class car {
    String num_pl;
    engine e;

    void run() {
        System.out.println( num_pl + " runs w " + e.hp + " HP");

    }
}
class engine {
    int hp;
    boolean electric;
}
