import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author Mike
 */
public class houseofcards{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger n, p;
        n =sc.nextBigInteger();
        BigInteger big1 = new BigInteger("3");
        BigInteger big2 = new BigInteger("1");
        BigInteger big3 = new BigInteger("2");
        BigInteger big4 = new BigInteger("4");
        BigInteger big5 = new BigInteger("0");
        while(true){
            
            p = n.multiply(big1);
            p = p.add(big2);
            p = p.multiply(n);
            p= p.divide(big3);
            //System.out.print(p+" ");
            //System.out.println(p.mod(big4));
            
            if(p.mod(big4).equals(big5)){
                break;
            }
            n = n.add(big2);
        }
        System.out.println(n);
    
    }
    
}
