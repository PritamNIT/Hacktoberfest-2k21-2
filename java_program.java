/*
 * 2) Write a java program to input two strings str1, str2, and a length k, and output whether
	  both string has a common substring of length k. If found, write the initial index of matching
	  substring of both str1 and str2.
 */

import java.util.Scanner;

public class Main {
	
	public void matchingString(String str1,String str2,int k) {
        for(int i=0;i<str1.length();++i) {
            for(int j=0;j<str2.length();++j) {
                char ch1=str1.charAt(i);
                char ch2=str2.charAt(j);
                if(ch1==ch2) {
                    int temp1=i+1;
                    int temp2=j+1;
                    int cnt=0;
                    while(ch1==ch2 && temp1<str1.length() && temp2<str2.length()) {
                        ch1=str1.charAt(temp1);
                        ch2=str2.charAt(temp2);
                        temp1++;
                        temp2++;
                        cnt++;
                        if(cnt==k) {
                            System.out.println("True, "+i+", "+j);
                            return;
                        }
                    }
                }
            }
        }
        System.out.println("False");
    }
	public static void main(String[] args) {
		  Scanner var = new Scanner(System.in);
		  System.out.print("Enter first string: ");
		  String str1 = var.nextLine();
		  System.out.print("Enter second string: ");
		  String str2 = var.nextLine();
		  System.out.print("Enter the length of common string: ");
		  int len = var.nextInt();
		  Main obj = new Main();
		  obj.matchingString(str1, str2, len);
	}

}
