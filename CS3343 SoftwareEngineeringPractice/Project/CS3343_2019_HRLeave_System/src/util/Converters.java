package util;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class Converters {

	public static String bytesToHex(byte[] bytes) {

		StringBuilder sb = new StringBuilder();
		for (byte b : bytes) {
			sb.append(String.format("%02x", b));
		}
		return sb.toString();

	}

	public static byte[] hexToBytes(String str) {
		int len = str.length();
		byte[] data = new byte[len / 2];
		for (int i = 0; i < len; i += 2) {
			data[i / 2] = (byte) ((Character.digit(str.charAt(i), 16) << 4) + Character.digit(str.charAt(i + 1), 16));
		}
		return data;

	}

	public static String date2Str(Date d) {
		SimpleDateFormat sdformat = new SimpleDateFormat("yyyy-MM-dd");
		return sdformat.format(d);
	}
	
	public static String calendar2Str(Calendar d) {
		SimpleDateFormat sdformat = new SimpleDateFormat("yyyy-MM-dd");
		return sdformat.format(d.getTime());
	}
	
	public static Date str2Date(String str) {
		try {
			SimpleDateFormat sdformat = new SimpleDateFormat("yyyy-MM-dd");
			return sdformat.parse(str);
		} catch (ParseException e) {
			System.out.println(e);
		}
		return null;
	}
	
	public static Calendar str2Calendar(String str) {
		Date d = str2Date(str);
		Calendar cal = Calendar.getInstance();
		cal.setTime(d);
		return cal;
	}
	
	public static boolean str2Bool(String str) {
		return str == "1";
	}
	
}
