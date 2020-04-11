
public class Member implements Comparable<Member> {
	
	private Employee e;
	private Role role;

	public Member(Role role, Employee e) {
		
		this.role = role;
		this.e = e;
		
	}
	
	public String getName () {
		return this.e.toString();
	}
	
	public Employee getEmployee () {
		return e;
	}
	
	
	public Role getRole() {
		return role;
	}
	
	public void setRole ( Role newRole) {
		this.role = newRole;
	}
	
	public String getNameAndRole() {
		return this.role.getNameAndRole(this.e);
	}
	
	public String getDescription() {
		return this.role.getDescription();
	}

	@Override
	public int compareTo(Member anotherMember) {
		return this.e.getName().compareTo(anotherMember.e.getName());
	}


}


