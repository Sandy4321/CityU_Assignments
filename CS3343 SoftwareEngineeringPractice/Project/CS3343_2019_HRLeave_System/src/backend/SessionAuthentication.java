package backend;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Calendar;

import exception.NoResultException;
import exception.StringLengthExceededException;
import util.Converters;
import util.HashingCalculator;

public class SessionAuthentication implements Authentication {

//	public destorySession() {
//		
//	}

	private int eid;
	private String sid;

	private DBConnect con;

	public SessionAuthentication(String sid, int eid, DBConnect con) {
		this.sid = sid;
		this.eid = eid;
		this.con = con;
	}

	public static String createSession(int eid, DBConnect con) {
		/*
		 * Session algorithm: session_id = SHA2(eid+time + random_num);
		 */
		Calendar now = Calendar.getInstance();

		Calendar expiry = Calendar.getInstance();
		expiry.add(Calendar.DAY_OF_MONTH, 1);

		String hash_string = eid + "" + now.getTime();

		byte[] session = new byte[260];
		if (hash_string.length() > 256) {
			return null;
		}
		session = HashingCalculator.genHash_SHA1PRNG(hash_string);
		String sessionStr = Converters.bytesToHex(session);

		// store in db
		try {
			con.insertSession(eid, sessionStr, expiry);
		} catch (SQLException e) {
			System.out.println(e);
			return null;
		}

		return sessionStr;
	}

	public void destorySession() throws SQLException {
		this.con.removeSession(this.sid);	
	}

	@Override
	public boolean authenticate() throws SQLException {

		try {
			ArrayList<String[]> results = this.processListOfSession();
			for (String[] result: results) {
				System.out.println(result[0]);
				if (result[0].equals(this.sid)) {
					return true;
				}
			}
			return false;
		} catch (NoResultException e) {
			return false;
		}

	}

	private ArrayList<String[]> processListOfSession() throws SQLException, NoResultException {
		ArrayList<String[]> results = this.con.getUserSessionInfo(this.eid);
		
		// choose to remove sid that have expired.
		ArrayList<String[]> expiredResults = new ArrayList<>();
		ArrayList<String[]> unexpiredResults = new ArrayList<>();
		for (String[] result : results) {
			Calendar expiry = Converters.str2Calendar(result[1]);
			if (expiry.after(Calendar.getInstance())) {
				unexpiredResults.add(result);
			}else {
				expiredResults.add(result);
			}
		}
		
		for(String[] expiredResult : expiredResults) {
			try {
				this.con.removeSession(expiredResult[0]);	
			} catch (SQLException e) {
				System.out.println(e);
			}
		}
		
		return unexpiredResults;
	}
}
