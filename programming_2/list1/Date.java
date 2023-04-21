/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author geedorah
 */
public class Date {

    int day;
    int month;
    int year;

    Date() {
        day = 0;
        month = 0;
        year = 0;
    }

    Date(int year) {
        day = 1;
        month = 1;
        this.year = year;
    }

    Date(int day, int month, int year) {
        this.day = day;
        this.month = month;
        this.year = year;
    }

    String formatDate(char separator) {
        String formated = "" + day + separator + month + separator + year;
        return formated;
    }

    public static void main(String args[]) {
        Date date = new Date(18, 4, 2023);
        Date date1 = new Date();
        Date date2 = new Date(2023);

        System.out.println(date.formatDate('-'));
    }
}
