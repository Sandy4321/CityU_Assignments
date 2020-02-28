import java.util.*;

public abstract class RecordedCommand implements Command {

	private static ArrayList<RecordedCommand> undoList = new ArrayList<>();
	private static ArrayList<RecordedCommand> redoList = new ArrayList<>();

	@Override
	public abstract void execute(String[] cmdParts);

	public abstract void undoMe();

	public abstract void redoMe();

	protected static void clearRedoList() {
		redoList.clear();
	}

	protected static void addRedoCommand(RecordedCommand c) {
		redoList.add(c);
	}

	protected static void addUndoCommand(RecordedCommand c) {
		undoList.add(c);
	}

	public static void undoOneCommand() {
		if (!undoList.isEmpty()) {
			undoList.remove(undoList.size() - 1).undoMe();
		}
	}

	public static void redoOneCommand() {
		if (!redoList.isEmpty()) {
			redoList.remove(redoList.size() - 1).redoMe();
		}
	}

}
