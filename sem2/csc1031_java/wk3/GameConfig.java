// GameConfig.java
class Games {
    private static Games config;
    private String difficulty;
    private int volume;

    private Games() {
        // default settings
        this.difficulty = "normal";
        this.volume = 50;
    }

    public static Games getInstance() {
        if (config == null) {
            config = new Games();
        }
        return config;
    }

    public String getDifficulty() {
        return difficulty;
    }
    public Integer getVolume() {
        return volume;
    }
    public void setDifficulty(String difficulty) {
        this.difficulty = difficulty;
    }

    public void setVolume(Integer volume) {
        this.volume = volume;
    }
}

public class GameConfig {
    public static void main(String[] args) {
        Games config = Games.getInstance();
        System.out.println("Difficulty : " + config.getDifficulty());
        System.out.println("Volume : " + config.getVolume());

        config.setDifficulty("Hard");
        config.setVolume(12);

        Games config2 = Games.getInstance(); // same instance
        System.out.println("New Diff: " + config2.getDifficulty());
        System.out.println("New Vol1 " + config.getVolume());
        System.out.println("New Vol2 " + config2.getVolume());
        
    }
}