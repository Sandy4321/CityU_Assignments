package backend;

import java.security.spec.InvalidKeySpecException;
import java.sql.SQLException;
import java.util.Arrays;

import exception.NoResultException;
import util.Converters;
import util.HashingCalculator;

public class LoginAuthentication implements Authentication {

	private String username;
	private String password;
	
	private DBConnect con;

	public LoginAuthentication(String username, String password, DBConnect con) {
		this.username = username;
		this.password = password;
		this.con = con;
	}

	@Override
	public boolean authenticate() throws SQLException {
		try {
			String[] authInfo = this.con.getUserAuthInfo(username);
			byte[] passwordHashed = Converters.hexToBytes(authInfo[0]);
			byte[] salt = Converters.hexToBytes(authInfo[1]);

			byte[] inputHashed = HashingCalculator.genHash(this.password, salt);
			return Arrays.equals(inputHashed, passwordHashed);
		} catch (NoResultException e) {
			System.out.println(e);
			return false;
		}
	}
}