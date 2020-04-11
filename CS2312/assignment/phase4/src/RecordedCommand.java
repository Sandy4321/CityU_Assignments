import java.util.ArrayList;
import java.util.List;

public abstract class RecordedCommand implements Command {

	private static List<RecordedCommand> undoList = new ArrayList<>();
	private static List<RecordedCommand> redoList = new ArrayList<>();
	
	// doesn't require to write execute
	
	public abstract void undoMe();
	public abstract void redoMe();
	
	protected static void clearRedoList () {
		redoList.clear();
	}
	
	protected static void addUndoCommand ( RecordedCommand undoCommand ) {
		undoList.add(undoCommand);
	}
	
	protected static void addRedoCommand ( RecordedCommand redoCommand ) {
		redoList.add(redoCommand);
	}
	
	protected static void undoOneCommand () {
		if ( ! undoList.isEmpty() ) {
			undoList.remove(undoList.size() - 1).undoMe();
		} else {
			System.out.println( "Nothing to undo." );
		}
	}

	protected static void redoOneCommand () {
		if ( ! redoList.isEmpty() ) {
			redoList.remove(redoList.size() - 1).redoMe();
		} else {
			System.out.println( "Nothing to redo." );
		}
	}
}
