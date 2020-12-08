/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package omegarecu;

import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Scanner;

/**
 *
 * @author Mike
 */
public class hk {
       public static void main(String[] args) {
           Scanner sc = new Scanner(System.in);
           int n, cases=1;
           n = sc.nextInt();
           for (int i = 0; i < n; i++) {
            String cad;
            cad = sc.next();
            cad+="-";
            int month = Integer.parseInt(cad.substring(0, 2));
            int  day = Integer.parseInt(cad.substring(2,4));
            int year = Integer.parseInt(cad.substring(4, 8));
            
             
             GregorianCalendar calendar = new GregorianCalendar();
             calendar.set(year, month-1, day);
             calendar.add(Calendar.DATE, 280);
             int year1 = calendar.get(Calendar.YEAR);
             int m = calendar.get(Calendar.MONTH)+1;
             int d = calendar.get(Calendar.DAY_OF_MONTH);

             //System.out.print(cases+" "+m+"/" + d + "/" + year1+" ");
               System.out.print(cases+" ");
               if(m<10){
                   System.out.print("0"+m+"/");
               }else System.out.print(m+"/");
               if(d<10) System.out.print("0"+d+"/");
               else System.out.print(d+"/");
               System.out.print(year1+" ");
             cases++;
             if((m==1 && d >= 21) || (m==2 && d>=1 && d<=19) ){
                 System.out.println("aquarius");
             }else if ((m==2 && d>=20) || (m==3 && d>=1 && d<=20)){
                 System.out.println("pisces");
             }else if((m==3 && d>=21) || (m==4 && d>=1 && d<=20)){
                 System.out.println("aries");
             }else if((m==4 && d>=21) || (m==5 && d>=1 && d<=21)){
                 System.out.println("taurus");
             }else if((m==5 && d>=22) || (m==6 && d>=1 && d<=21)){
                 System.out.println("gemini");
             }else if((m==6 && d>=22) || (m==7 && d>=1 && d<=22)){
                 System.out.println("cancer");
             }else if((m==7 && d>=23) || (m==8 && d>=1 && d<=21)){
                 System.out.println("leo");
             }else if((m==8 && d>=22) || (m==9 && d>=1 && d<=23)){
                 System.out.println("virgo");
             }else if((m==9 && d>=24) || (m==10 && d>=1 && d<=23)){
                 System.out.println("libra");
             }else if((m==10 && d>=24) || (m==11 && d>=1 && d<=22)){
                 System.out.println("scorpio");
             }else if((m==11 && d>=23) || (m==12 && d>=1 && d<=22)){
                 System.out.println("sagittarius");
             }else if((m==12 && d>=23) || (m==1 && d>=1 && d<=20)){
                 System.out.println("capricorn");
             }
          }
       }
}   
