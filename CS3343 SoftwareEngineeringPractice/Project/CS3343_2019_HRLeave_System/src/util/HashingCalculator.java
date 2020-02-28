package util;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;
import java.security.spec.InvalidKeySpecException;
import java.security.spec.KeySpec;

import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.PBEKeySpec;

import exception.StringLengthExceededException;

public class HashingCalculator {
	
	public static byte[] genSalt() {
		SecureRandom random = new SecureRandom();
		byte[] salt = new byte[16];
		random.nextBytes(salt);
		return salt;
	}
	
	public static byte[] genHash(String str2Hash, byte[] salt)
	{
		// have to check the length let you write some bug report str2Hash should be shorter because db only accept 255 chars.
		try {
			KeySpec spec = new PBEKeySpec(str2Hash.toCharArray(), salt, 65536, 128);
			
			SecretKeyFactory factory = SecretKeyFactory.getInstance("PBKDF2WithHmacSHA1");

			byte[] hash = factory.generateSecret(spec).getEncoded();
			return hash;
		} catch (NoSuchAlgorithmException e) {
			System.out.println(e);
		} catch (InvalidKeySpecException e) {
			System.out.println(e);
		}
		return new byte[0];
	}
	
	public static byte[] genHash_SHA1PRNG(String str2Hash)
	{
		// output byte length is 
		// hash = SHA_256(str2Hash) + padded_random_numbers;
		// final output length is 128 hexadecimal size 
		// 32 byte = 64 hexadecimal
		// maximum 32 bytes of data + minimum 32 bytes of random numbers;
		
		// initialise all result;
		byte[] result = new byte[64]; // 32 bytes of randomness
		try {
			SecureRandom random = SecureRandom.getInstance("SHA1PRNG");
			random.nextBytes(result);
			
			//sha256
		    byte[] str2HashBytes = HashingCalculator.genHash_SHA256(str2Hash);
		    
		    // replace part of random with actual username; ignore 4 bytes of data
		    for (int i = 0; i < str2HashBytes.length; i++) {
		    	result[i] = str2HashBytes[i]; // replace the part of result;
		    }
		    return result;
		} catch (NoSuchAlgorithmException e) {
			System.out.println(e);
		}

	    return null;
	}
	
	public static byte[] genHash_SHA256(String str2Hash)
	{
		byte[] result = new byte[32];
		try {
			//sha256
			MessageDigest sha256 = MessageDigest.getInstance("SHA-256");
			result = sha256.digest(str2Hash.getBytes());
			return result;
		} catch (NoSuchAlgorithmException e) {
			System.out.println(e);
		}
	    return null;
	}

}
