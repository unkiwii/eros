// Generated from ../newlang.g4 by ANTLR 4.4
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class newlangLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.4", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__6=1, T__5=2, T__4=3, T__3=4, T__2=5, T__1=6, T__0=7, IMPORT=8, SELF=9, 
		TYPE=10, ABSTRACT=11, EXTENDS=12, STATIC=13, PRIMITIVE=14, NULL=15, BOOLEAN=16, 
		STRING=17, COMMENT=18, NUMBER=19, NL=20, SPACE=21, ASSIGNATION=22, END=23, 
		FILE_EXTENSION=24, LIBRARY_EXTENSION=25, FOLDER_UP=26, FOLDER_SEPARATOR=27, 
		OPEN_BLOCK=28, CLOSE_BLOCK=29, BLOCK_HEADER_SEPARATOR=30, COLON=31, BLOCK_ARGUMENT_SEPARATOR=32, 
		LPAREN=33, RPAREN=34, NAME=35, TYPE_NAME=36, LOWER_CASE=37, UPPER_CASE=38;
	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] tokenNames = {
		"'\\u0000'", "'\\u0001'", "'\\u0002'", "'\\u0003'", "'\\u0004'", "'\\u0005'", 
		"'\\u0006'", "'\\u0007'", "'\b'", "'\t'", "'\n'", "'\\u000B'", "'\f'", 
		"'\r'", "'\\u000E'", "'\\u000F'", "'\\u0010'", "'\\u0011'", "'\\u0012'", 
		"'\\u0013'", "'\\u0014'", "'\\u0015'", "'\\u0016'", "'\\u0017'", "'\\u0018'", 
		"'\\u0019'", "'\\u001A'", "'\\u001B'", "'\\u001C'", "'\\u001D'", "'\\u001E'", 
		"'\\u001F'", "' '", "'!'", "'\"'", "'#'", "'$'", "'%'", "'&'"
	};
	public static final String[] ruleNames = {
		"T__6", "T__5", "T__4", "T__3", "T__2", "T__1", "T__0", "IMPORT", "SELF", 
		"TYPE", "ABSTRACT", "EXTENDS", "STATIC", "PRIMITIVE", "NULL", "BOOLEAN", 
		"STRING", "COMMENT", "NUMBER", "INT", "NL", "SPACE", "ASSIGNATION", "END", 
		"FILE_EXTENSION", "LIBRARY_EXTENSION", "FOLDER_UP", "FOLDER_SEPARATOR", 
		"OPEN_BLOCK", "CLOSE_BLOCK", "BLOCK_HEADER_SEPARATOR", "COLON", "BLOCK_ARGUMENT_SEPARATOR", 
		"LPAREN", "RPAREN", "NAME", "TYPE_NAME", "LOWER_CASE", "UPPER_CASE"
	};


	public newlangLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "newlang.g4"; }

	@Override
	public String[] getTokenNames() { return tokenNames; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\2(\u010d\b\1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\3\2\3\2\3\3\3\3\3\4"+
		"\3\4\3\5\3\5\3\6\3\6\3\7\3\7\3\b\3\b\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\n\3"+
		"\n\3\n\3\n\3\n\3\13\3\13\3\13\3\13\3\13\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3"+
		"\f\3\f\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\16\3\16\3\16\3\16\3\16\3\16\3"+
		"\16\3\17\3\17\3\17\3\17\3\17\3\17\3\17\3\17\3\17\3\17\3\20\3\20\3\20\3"+
		"\20\3\20\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\5\21\u00a1\n\21"+
		"\3\22\3\22\7\22\u00a5\n\22\f\22\16\22\u00a8\13\22\3\22\3\22\3\23\3\23"+
		"\7\23\u00ae\n\23\f\23\16\23\u00b1\13\23\3\23\3\23\3\23\3\23\3\24\5\24"+
		"\u00b8\n\24\3\24\3\24\3\24\6\24\u00bd\n\24\r\24\16\24\u00be\3\24\5\24"+
		"\u00c2\n\24\3\24\5\24\u00c5\n\24\3\25\3\25\3\25\7\25\u00ca\n\25\f\25\16"+
		"\25\u00cd\13\25\5\25\u00cf\n\25\3\26\3\26\3\27\3\27\3\30\3\30\3\30\3\31"+
		"\3\31\3\32\3\32\3\32\3\32\3\33\3\33\3\33\3\33\3\33\3\33\3\34\3\34\3\34"+
		"\3\35\3\35\3\36\3\36\3\37\3\37\3 \3 \3!\3!\3\"\3\"\3\"\3#\3#\3$\3$\3%"+
		"\3%\3%\3%\7%\u00fc\n%\f%\16%\u00ff\13%\3&\3&\3&\3&\7&\u0105\n&\f&\16&"+
		"\u0108\13&\3\'\3\'\3(\3(\4\u00a6\u00af\2)\3\3\5\4\7\5\t\6\13\7\r\b\17"+
		"\t\21\n\23\13\25\f\27\r\31\16\33\17\35\20\37\21!\22#\23%\24\'\25)\2+\26"+
		"-\27/\30\61\31\63\32\65\33\67\349\35;\36=\37? A!C\"E#G$I%K&M\'O(\3\2\6"+
		"\3\2\62;\3\2\63;\3\2c|\3\2C\\\u011a\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2"+
		"\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23"+
		"\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2"+
		"\2\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2+\3\2"+
		"\2\2\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2\2\2\67"+
		"\3\2\2\2\29\3\2\2\2\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2\2\2A\3\2\2\2\2C\3\2"+
		"\2\2\2E\3\2\2\2\2G\3\2\2\2\2I\3\2\2\2\2K\3\2\2\2\2M\3\2\2\2\2O\3\2\2\2"+
		"\3Q\3\2\2\2\5S\3\2\2\2\7U\3\2\2\2\tW\3\2\2\2\13Y\3\2\2\2\r[\3\2\2\2\17"+
		"]\3\2\2\2\21_\3\2\2\2\23f\3\2\2\2\25k\3\2\2\2\27p\3\2\2\2\31y\3\2\2\2"+
		"\33\u0081\3\2\2\2\35\u0088\3\2\2\2\37\u0092\3\2\2\2!\u00a0\3\2\2\2#\u00a2"+
		"\3\2\2\2%\u00ab\3\2\2\2\'\u00c4\3\2\2\2)\u00ce\3\2\2\2+\u00d0\3\2\2\2"+
		"-\u00d2\3\2\2\2/\u00d4\3\2\2\2\61\u00d7\3\2\2\2\63\u00d9\3\2\2\2\65\u00dd"+
		"\3\2\2\2\67\u00e3\3\2\2\29\u00e6\3\2\2\2;\u00e8\3\2\2\2=\u00ea\3\2\2\2"+
		"?\u00ec\3\2\2\2A\u00ee\3\2\2\2C\u00f0\3\2\2\2E\u00f3\3\2\2\2G\u00f5\3"+
		"\2\2\2I\u00f7\3\2\2\2K\u0100\3\2\2\2M\u0109\3\2\2\2O\u010b\3\2\2\2QR\7"+
		"(\2\2R\4\3\2\2\2ST\7@\2\2T\6\3\2\2\2UV\7-\2\2V\b\3\2\2\2WX\7/\2\2X\n\3"+
		"\2\2\2YZ\7,\2\2Z\f\3\2\2\2[\\\7>\2\2\\\16\3\2\2\2]^\7?\2\2^\20\3\2\2\2"+
		"_`\7k\2\2`a\7o\2\2ab\7r\2\2bc\7q\2\2cd\7t\2\2de\7v\2\2e\22\3\2\2\2fg\7"+
		"u\2\2gh\7g\2\2hi\7n\2\2ij\7h\2\2j\24\3\2\2\2kl\7v\2\2lm\7{\2\2mn\7r\2"+
		"\2no\7g\2\2o\26\3\2\2\2pq\7c\2\2qr\7d\2\2rs\7u\2\2st\7v\2\2tu\7t\2\2u"+
		"v\7c\2\2vw\7e\2\2wx\7v\2\2x\30\3\2\2\2yz\7g\2\2z{\7z\2\2{|\7v\2\2|}\7"+
		"g\2\2}~\7p\2\2~\177\7f\2\2\177\u0080\7u\2\2\u0080\32\3\2\2\2\u0081\u0082"+
		"\7u\2\2\u0082\u0083\7v\2\2\u0083\u0084\7c\2\2\u0084\u0085\7v\2\2\u0085"+
		"\u0086\7k\2\2\u0086\u0087\7e\2\2\u0087\34\3\2\2\2\u0088\u0089\7r\2\2\u0089"+
		"\u008a\7t\2\2\u008a\u008b\7k\2\2\u008b\u008c\7o\2\2\u008c\u008d\7k\2\2"+
		"\u008d\u008e\7v\2\2\u008e\u008f\7k\2\2\u008f\u0090\7x\2\2\u0090\u0091"+
		"\7g\2\2\u0091\36\3\2\2\2\u0092\u0093\7p\2\2\u0093\u0094\7w\2\2\u0094\u0095"+
		"\7n\2\2\u0095\u0096\7n\2\2\u0096 \3\2\2\2\u0097\u0098\7v\2\2\u0098\u0099"+
		"\7t\2\2\u0099\u009a\7w\2\2\u009a\u00a1\7g\2\2\u009b\u009c\7h\2\2\u009c"+
		"\u009d\7c\2\2\u009d\u009e\7n\2\2\u009e\u009f\7u\2\2\u009f\u00a1\7g\2\2"+
		"\u00a0\u0097\3\2\2\2\u00a0\u009b\3\2\2\2\u00a1\"\3\2\2\2\u00a2\u00a6\7"+
		"$\2\2\u00a3\u00a5\13\2\2\2\u00a4\u00a3\3\2\2\2\u00a5\u00a8\3\2\2\2\u00a6"+
		"\u00a7\3\2\2\2\u00a6\u00a4\3\2\2\2\u00a7\u00a9\3\2\2\2\u00a8\u00a6\3\2"+
		"\2\2\u00a9\u00aa\7$\2\2\u00aa$\3\2\2\2\u00ab\u00af\7%\2\2\u00ac\u00ae"+
		"\13\2\2\2\u00ad\u00ac\3\2\2\2\u00ae\u00b1\3\2\2\2\u00af\u00b0\3\2\2\2"+
		"\u00af\u00ad\3\2\2\2\u00b0\u00b2\3\2\2\2\u00b1\u00af\3\2\2\2\u00b2\u00b3"+
		"\5+\26\2\u00b3\u00b4\3\2\2\2\u00b4\u00b5\b\23\2\2\u00b5&\3\2\2\2\u00b6"+
		"\u00b8\7/\2\2\u00b7\u00b6\3\2\2\2\u00b7\u00b8\3\2\2\2\u00b8\u00b9\3\2"+
		"\2\2\u00b9\u00ba\5)\25\2\u00ba\u00bc\7.\2\2\u00bb\u00bd\t\2\2\2\u00bc"+
		"\u00bb\3\2\2\2\u00bd\u00be\3\2\2\2\u00be\u00bc\3\2\2\2\u00be\u00bf\3\2"+
		"\2\2\u00bf\u00c5\3\2\2\2\u00c0\u00c2\7/\2\2\u00c1\u00c0\3\2\2\2\u00c1"+
		"\u00c2\3\2\2\2\u00c2\u00c3\3\2\2\2\u00c3\u00c5\5)\25\2\u00c4\u00b7\3\2"+
		"\2\2\u00c4\u00c1\3\2\2\2\u00c5(\3\2\2\2\u00c6\u00cf\7\62\2\2\u00c7\u00cb"+
		"\t\3\2\2\u00c8\u00ca\t\2\2\2\u00c9\u00c8\3\2\2\2\u00ca\u00cd\3\2\2\2\u00cb"+
		"\u00c9\3\2\2\2\u00cb\u00cc\3\2\2\2\u00cc\u00cf\3\2\2\2\u00cd\u00cb\3\2"+
		"\2\2\u00ce\u00c6\3\2\2\2\u00ce\u00c7\3\2\2\2\u00cf*\3\2\2\2\u00d0\u00d1"+
		"\7\f\2\2\u00d1,\3\2\2\2\u00d2\u00d3\7\"\2\2\u00d3.\3\2\2\2\u00d4\u00d5"+
		"\7<\2\2\u00d5\u00d6\7?\2\2\u00d6\60\3\2\2\2\u00d7\u00d8\7\60\2\2\u00d8"+
		"\62\3\2\2\2\u00d9\u00da\7\60\2\2\u00da\u00db\7p\2\2\u00db\u00dc\7n\2\2"+
		"\u00dc\64\3\2\2\2\u00dd\u00de\7\60\2\2\u00de\u00df\7p\2\2\u00df\u00e0"+
		"\7n\2\2\u00e0\u00e1\7k\2\2\u00e1\u00e2\7d\2\2\u00e2\66\3\2\2\2\u00e3\u00e4"+
		"\7\60\2\2\u00e4\u00e5\7\60\2\2\u00e58\3\2\2\2\u00e6\u00e7\7\61\2\2\u00e7"+
		":\3\2\2\2\u00e8\u00e9\7]\2\2\u00e9<\3\2\2\2\u00ea\u00eb\7_\2\2\u00eb>"+
		"\3\2\2\2\u00ec\u00ed\7~\2\2\u00ed@\3\2\2\2\u00ee\u00ef\7<\2\2\u00efB\3"+
		"\2\2\2\u00f0\u00f1\7.\2\2\u00f1\u00f2\7\"\2\2\u00f2D\3\2\2\2\u00f3\u00f4"+
		"\7*\2\2\u00f4F\3\2\2\2\u00f5\u00f6\7+\2\2\u00f6H\3\2\2\2\u00f7\u00fd\5"+
		"M\'\2\u00f8\u00fc\5M\'\2\u00f9\u00fc\5O(\2\u00fa\u00fc\5)\25\2\u00fb\u00f8"+
		"\3\2\2\2\u00fb\u00f9\3\2\2\2\u00fb\u00fa\3\2\2\2\u00fc\u00ff\3\2\2\2\u00fd"+
		"\u00fb\3\2\2\2\u00fd\u00fe\3\2\2\2\u00feJ\3\2\2\2\u00ff\u00fd\3\2\2\2"+
		"\u0100\u0106\5O(\2\u0101\u0105\5M\'\2\u0102\u0105\5O(\2\u0103\u0105\5"+
		")\25\2\u0104\u0101\3\2\2\2\u0104\u0102\3\2\2\2\u0104\u0103\3\2\2\2\u0105"+
		"\u0108\3\2\2\2\u0106\u0104\3\2\2\2\u0106\u0107\3\2\2\2\u0107L\3\2\2\2"+
		"\u0108\u0106\3\2\2\2\u0109\u010a\t\4\2\2\u010aN\3\2\2\2\u010b\u010c\t"+
		"\5\2\2\u010cP\3\2\2\2\20\2\u00a0\u00a6\u00af\u00b7\u00be\u00c1\u00c4\u00cb"+
		"\u00ce\u00fb\u00fd\u0104\u0106\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}