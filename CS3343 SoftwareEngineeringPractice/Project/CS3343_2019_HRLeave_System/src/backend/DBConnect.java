package backend;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;

import exception.NoResultException;
import user.Leave;
import util.Converters;

public class DBConnect {
	
	private Connection con;
	
	public DBConnect () {
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			con = DriverManager.getConnection("jdbc:mysql://localhost:3306/","root","");
			Statement st = con.createStatement();
			st.executeQuery("USE cs3343db;");
		} catch (Exception e){
			System.out.println("Error: "+ e.toString());
		}
	}
	
	public void getData() {
		try {
			String query = "SELECT * from Employee;";
			Statement st = con.createStatement();
			ResultSet rs = st.executeQuery(query);
			System.out.println("Records from Database.");
			while (rs.next()) {
				String name = rs.getString("name");
				String age = rs.getString("age");
				System.out.println(name + ' ' + age);
			}
		} catch (Exception e) {
			System.out.println(e);
		}
	}

	private ArrayList<String[]> executeAndFetch(String sql, String[] responseOrders) throws SQLException {
		/*
		 * responseOrders: array of strings to organise the order of the columns
		 * */
		try {
			Statement st = con.createStatement();
			ResultSet rs = st.executeQuery(sql);

			ArrayList<String[]> response = new ArrayList<String[]>();
			while (rs.next()) {
				String[] singleRowResponse = new String[responseOrders.length];
				for (int i = 0; i < responseOrders.length; i++) {
					singleRowResponse[i] = rs.getString(responseOrders[i]);
				}
				response.add(singleRowResponse);
			}
			return response;
		} catch (SQLException e) {
			System.out.println(e);
			throw e;
		}
	}
	
	public String[] getUserAuthInfo(String username) throws SQLException, NoResultException {
		try {
			return this.executeAndFetch(
					String.format("SELECT password, salt FROM Employee WHERE username=\"%s\";", username),
					new String[] {"password","salt"}
					
			).get(0);
		} catch (IndexOutOfBoundsException e) {
			System.out.println(e);
			throw new NoResultException("User don't exist.");
		}
	}
	
	public String getUserEid(String username) throws SQLException, NoResultException {
		try {
			return this.executeAndFetch(
					String.format("SELECT eid FROM Employee WHERE username=\"%s\";", username),
					new String[] {"eid"}
					
			).get(0)[0];
		} catch (IndexOutOfBoundsException e) {
			System.out.println(e);
			throw new NoResultException("User don't exist.");
		}
	}
	
	public void insertUser(String name, Calendar dateJoined, String username, String salt, String password,boolean isManager, boolean isSenior) throws SQLException {
		Statement st = con.createStatement();
		st.executeUpdate(String.format("INSERT INTO Employee (name, dateJoined, username, salt, password,isManager,isSenior) VALUES (\"%s\",\"%s\",\"%s\",\"%s\",\"%s\", %b, %b);",name ,Converters.calendar2Str(dateJoined), username,salt, password,isManager,isSenior));
	}
	
	public void insertSession(int eid, String sid, Calendar expiry_date) throws SQLException {
		Statement st = con.createStatement();
		st.executeUpdate(String.format("INSERT INTO Session VALUES (%d,\"%s\",\"%s\");",eid ,sid,Converters.calendar2Str(expiry_date)));
	}
	
	public ArrayList<String[]> getUserSessionInfo(int eid) throws SQLException {
		Statement st = con.createStatement();
		return this.executeAndFetch(String.format("SELECT sid, expiry FROM Session WHERE eid=%d;", eid),new String[] {"sid","expiry"});
	}

	public void removeSession(String sid) throws SQLException {
		Statement st = con.createStatement();
		st.executeUpdate(String.format("DELETE FROM Session WHERE sid=\"%s\";", sid));
	}
	
	public Object[] getUser(int eid) throws SQLException, NoResultException{
		try {
			String[] rawRes = this.executeAndFetch(
					String.format("SELECT name, age, dateJoined, username, isManager, isSenior FROM Employee WHERE eid=%s;", eid),
					new String[] {"name","age","dateJoined","username","isManager", "isSenior"}
			).get(0);
			return new Object[]{ 
					rawRes[0], 
					Integer.parseInt(rawRes[1]), 
					Converters.str2Calendar(rawRes[2]), 
					rawRes[3], 
					Converters.str2Bool(rawRes[4])  ,
					Converters.str2Bool(rawRes[5])
				};
		} catch (IndexOutOfBoundsException e) {
			System.out.println(e);
			throw new NoResultException("User don't exist.");
		}
	}

	public int getAnnualLeaveCount() {
		return 0;
	}
	
	public boolean insertLeave(ArrayList<Leave> leaves) {
		try {
			for (Leave leave : leaves) {
				Statement st = con.createStatement();
				st.executeUpdate(String.format("INSERT INTO onLeave (eid, leave_date, leave_type, type)  VALUES (%d,\"%s\",\"s\",\"%s\");",leave.getEmployee().getEid() ,Converters.calendar2Str(leave.getDate()),leave.getType(),"pending"));
			}
			return true;
		}catch(SQLException e){
			return false;
		}
	}
}