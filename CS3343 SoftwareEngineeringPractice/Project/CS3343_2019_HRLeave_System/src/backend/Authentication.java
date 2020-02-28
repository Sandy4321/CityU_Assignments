package backend;

import java.sql.SQLException;

public interface Authentication {
	
	public boolean authenticate() throws SQLException;
	
}
