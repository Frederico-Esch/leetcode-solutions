import java.io.StringWriter;

public class Main {
    public static void main(String[] args) {
        System.out.println(myAtoi("4193 with words"));
        System.out.println(myAtoi("with4193  words"));
        System.out.println(myAtoi("-91283472332"));
    }

    public static int myAtoi(String s){
        String trimmed = s.trim();
        boolean sign = false;
        int result = 0;
        if(trimmed.length() == 0) return 0;
        if(trimmed.charAt(0) == '-'){
            sign = true;
            trimmed = trimmed.substring(1);
        }else if(trimmed.charAt(0) == '+') trimmed = trimmed.substring(1);
        StringWriter sw = new StringWriter();
        trimmed.chars().takeWhile(p->{
            return Character.isDigit((char)p);
        }).forEach(sw::write);
        trimmed = sw.toString();
        try{
            result = Integer.valueOf(trimmed);
        }catch(Exception e){
            if(trimmed.length() == 0){
                result = 0;
            }else{
                if (sign) {
                    result = ((int)Math.pow(2, 31)*-1)-1;
                    sign = false;
                }else{
                    result = (int)Math.pow(2, 31);
                }
            }
        }
        if(sign) return result*-1;
        else return result;
    }
}