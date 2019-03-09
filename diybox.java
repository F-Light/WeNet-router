package cn.dyhack.test;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;



public class Md5Sum 
{
	public void algorithm(MessageDigest md5)
	{
		String account= "311937a7713465d1\n";
		String sum="tyxy#"+account;
		byte [] buf = sum.getBytes();
			md5.update(buf);
			byte [] tmp = md5.digest();
			StringBuilder sb = new StringBuilder();
			for (byte b:tmp) {
				sb.append(Integer.toHexString(b&0xff));
 
	}
	String a=(String) sb.toString().subSequence(7, 13);
	System.out.println(""+account.replace("\n", ""));
	System.out.println(""+a);
 }

	public static void main(String[] args) throws NoSuchAlgorithmException {
		new Md5Sum().algorithm(MessageDigest.getInstance("MD5"));
 }
 }