import java.awt.Robot;
import java.util.Random;
import java.awt.Toolkit;
import java.awt.Dimension;

public class MouseBot {
    public static final int ONE_HOUR = 3600 *1000;

    public static void main(String... args) throws Exception {
        Robot robot = new Robot();
        Random random = new Random();
        Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
        double screenHeight = screenSize.getHeight();
        double screenWidth = screenSize.getWidth();
        while (true) {
            robot.mouseMove(random.nextInt((int)screenWidth), random.nextInt((int)screenHeight));
            //uncomment & replace the other line to annoy the heck out of your victim
            //Thread.sleep(random.nextInt(ONE_HOUR));
            Thread.sleep(10000);
        }
    }
}