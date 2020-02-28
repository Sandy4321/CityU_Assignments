public class Member 
{
	//Instance fields
	private String name;
	private Role role;
	
	//Constructor
	public Member(String n,Role r) {
		name  = n;
		role = r;
	}
	
	//Assessor method
	public String getName() {
		return name;
	}
	public Role getRole() {
		return role;
	}
	public String getNameAndRole() {
		return role.getNameAndRole(this);
	}
	public void setRole(Role r) {
		role = r;
	}
	public String getRoleDescription() {
		return role.getRoleDescription();
	}
}