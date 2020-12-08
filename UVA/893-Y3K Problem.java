/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package omegarecu;

import java.io.BufferedReader;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Scanner;

/**
 *
 * @author Mike
 */
public class Uva {

    private static Object fileReader;

    public static void main(String[] args) {
        Scanner cs = new Scanner(System.in);
        int n, dia, mes, year;
        while (true) {

            n = cs.nextInt();
            dia = cs.nextInt();
            mes = cs.nextInt();
            year = cs.nextInt();
            if (n == 0 && dia == 0 && mes == 0 && year == 0) {
                break;
            }
            GregorianCalendar calendar = new GregorianCalendar();
            calendar.set(Calendar.YEAR, year);
            calendar.set(Calendar.MONTH, mes-1);
            calendar.set(Calendar.DAY_OF_MONTH, dia);
            calendar.add(Calendar.DATE, n);
            int year1 = calendar.get(Calendar.YEAR);
            int m = calendar.get(Calendar.MONTH)+1;
            int d = calendar.get(Calendar.DAY_OF_MONTH);

            System.out.println(d + " " + m + " " + year1);

        }

    }
}
