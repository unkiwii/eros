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
		T__0=1, SELF=2, TYPE=3, IMPORT=4, ABSTRACT=5, EXTENDS=6, STATIC=7, PRIMITIVE=8, 
		NULL=9, BOOLEAN=10, STRING=11, COMMENT=12, NUMBER=13, NL=14, SPACE=15, 
		ASSIGNATION=16, END=17, FILE_EXTENSION=18, LIBRARY_EXTENSION=19, FOLDER_UP=20, 
		FOLDER_SEPARATOR=21, OPEN_BLOCK=22, CLOSE_BLOCK=23, BLOCK_HEADER_SEPARATOR=24, 
		BLOCK_ARGUMENT_NAME_FINALIZER=25, BLOCK_ARGUMENT_SEPARATOR=26, NAME=27, 
		TYPE_NAME=28, LOWER_CASE=29, UPPER_CASE=30;
	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] tokenNames = {
		"'\\u0000'", "'\\u0001'", "'\\u0002'", "'\\u0003'", "'\\u0004'", "'\\u0005'", 
		"'\\u0006'", "'\\u0007'", "'\b'", "'\t'", "'\n'", "'\\u000B'", "'\f'", 
		"'\r'", "'\\u000E'", "'\\u000F'", "'\\u0010'", "'\\u0011'", "'\\u0012'", 
		"'\\u0013'", "'\\u0014'", "'\\u0015'", "'\\u0016'", "'\\u0017'", "'\\u0018'", 
		"'\\u0019'", "'\\u001A'", "'\\u001B'", "'\\u001C'", "'\\u001D'", "'\\u001E'"
	};
	public static final String[] ruleNames = {
		"T__0", "SELF", "TYPE", "IMPORT", "ABSTRACT", "EXTENDS", "STATIC", "PRIMITIVE", 
		"NULL", "BOOLEAN", "STRING", "COMMENT", "NUMBER", "INT", "NL", "SPACE", 
		"ASSIGNATION", "END", "FILE_EXTENSION", "LIBRARY_EXTENSION", "FOLDER_UP", 
		"FOLDER_SEPARATOR", "OPEN_BLOCK", "CLOSE_BLOCK", "BLOCK_HEADER_SEPARATOR", 
		"BLOCK_ARGUMENT_NAME_FINALIZER", "BLOCK_ARGUMENT_SEPARATOR", "NAME", "TYPE_NAME", 
		"LOWER_CASE", "UPPER_CASE"
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
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\2 \u00f0\b\1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \3\2"+
		"\3\2\3\2\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\4\3\4\3\4\3\4\3\4\3\5\3\5\3\5\3"+
		"\5\3\5\3\5\3\5\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\7\3\7\3\7\3\7\3\7"+
		"\3\7\3\7\3\7\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3"+
		"\t\3\t\3\t\3\n\3\n\3\n\3\n\3\n\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13"+
		"\3\13\5\13\u0088\n\13\3\f\3\f\7\f\u008c\n\f\f\f\16\f\u008f\13\f\3\f\3"+
		"\f\3\r\3\r\7\r\u0095\n\r\f\r\16\r\u0098\13\r\3\r\3\r\3\r\3\r\3\16\5\16"+
		"\u009f\n\16\3\16\3\16\3\16\6\16\u00a4\n\16\r\16\16\16\u00a5\3\16\5\16"+
		"\u00a9\n\16\3\16\5\16\u00ac\n\16\3\17\3\17\3\17\7\17\u00b1\n\17\f\17\16"+
		"\17\u00b4\13\17\5\17\u00b6\n\17\3\20\3\20\3\21\3\21\3\22\3\22\3\22\3\23"+
		"\3\23\3\24\3\24\3\24\3\24\3\25\3\25\3\25\3\25\3\25\3\25\3\26\3\26\3\26"+
		"\3\27\3\27\3\30\3\30\3\31\3\31\3\32\3\32\3\33\3\33\3\34\3\34\3\34\3\35"+
		"\3\35\3\35\3\35\7\35\u00df\n\35\f\35\16\35\u00e2\13\35\3\36\3\36\3\36"+
		"\3\36\7\36\u00e8\n\36\f\36\16\36\u00eb\13\36\3\37\3\37\3 \3 \4\u008d\u0096"+
		"\2!\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33\17\35"+
		"\2\37\20!\21#\22%\23\'\24)\25+\26-\27/\30\61\31\63\32\65\33\67\349\35"+
		";\36=\37? \3\2\6\3\2\62;\3\2\63;\3\2c|\3\2C\\\u00fd\2\3\3\2\2\2\2\5\3"+
		"\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2"+
		"\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3"+
		"\2\2\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3"+
		"\2\2\2\2+\3\2\2\2\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65"+
		"\3\2\2\2\2\67\3\2\2\2\29\3\2\2\2\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2\2\3A\3"+
		"\2\2\2\5F\3\2\2\2\7K\3\2\2\2\tP\3\2\2\2\13W\3\2\2\2\r`\3\2\2\2\17h\3\2"+
		"\2\2\21o\3\2\2\2\23y\3\2\2\2\25\u0087\3\2\2\2\27\u0089\3\2\2\2\31\u0092"+
		"\3\2\2\2\33\u00ab\3\2\2\2\35\u00b5\3\2\2\2\37\u00b7\3\2\2\2!\u00b9\3\2"+
		"\2\2#\u00bb\3\2\2\2%\u00be\3\2\2\2\'\u00c0\3\2\2\2)\u00c4\3\2\2\2+\u00ca"+
		"\3\2\2\2-\u00cd\3\2\2\2/\u00cf\3\2\2\2\61\u00d1\3\2\2\2\63\u00d3\3\2\2"+
		"\2\65\u00d5\3\2\2\2\67\u00d7\3\2\2\29\u00da\3\2\2\2;\u00e3\3\2\2\2=\u00ec"+
		"\3\2\2\2?\u00ee\3\2\2\2AB\7g\2\2BC\7x\2\2CD\7c\2\2DE\7n\2\2E\4\3\2\2\2"+
		"FG\7u\2\2GH\7g\2\2HI\7n\2\2IJ\7h\2\2J\6\3\2\2\2KL\7v\2\2LM\7{\2\2MN\7"+
		"r\2\2NO\7g\2\2O\b\3\2\2\2PQ\7k\2\2QR\7o\2\2RS\7r\2\2ST\7q\2\2TU\7t\2\2"+
		"UV\7v\2\2V\n\3\2\2\2WX\7c\2\2XY\7d\2\2YZ\7u\2\2Z[\7v\2\2[\\\7t\2\2\\]"+
		"\7c\2\2]^\7e\2\2^_\7v\2\2_\f\3\2\2\2`a\7g\2\2ab\7z\2\2bc\7v\2\2cd\7g\2"+
		"\2de\7p\2\2ef\7f\2\2fg\7u\2\2g\16\3\2\2\2hi\7u\2\2ij\7v\2\2jk\7c\2\2k"+
		"l\7v\2\2lm\7k\2\2mn\7e\2\2n\20\3\2\2\2op\7r\2\2pq\7t\2\2qr\7k\2\2rs\7"+
		"o\2\2st\7k\2\2tu\7v\2\2uv\7k\2\2vw\7x\2\2wx\7g\2\2x\22\3\2\2\2yz\7p\2"+
		"\2z{\7w\2\2{|\7n\2\2|}\7n\2\2}\24\3\2\2\2~\177\7v\2\2\177\u0080\7t\2\2"+
		"\u0080\u0081\7w\2\2\u0081\u0088\7g\2\2\u0082\u0083\7h\2\2\u0083\u0084"+
		"\7c\2\2\u0084\u0085\7n\2\2\u0085\u0086\7u\2\2\u0086\u0088\7g\2\2\u0087"+
		"~\3\2\2\2\u0087\u0082\3\2\2\2\u0088\26\3\2\2\2\u0089\u008d\7$\2\2\u008a"+
		"\u008c\13\2\2\2\u008b\u008a\3\2\2\2\u008c\u008f\3\2\2\2\u008d\u008e\3"+
		"\2\2\2\u008d\u008b\3\2\2\2\u008e\u0090\3\2\2\2\u008f\u008d\3\2\2\2\u0090"+
		"\u0091\7$\2\2\u0091\30\3\2\2\2\u0092\u0096\7%\2\2\u0093\u0095\13\2\2\2"+
		"\u0094\u0093\3\2\2\2\u0095\u0098\3\2\2\2\u0096\u0097\3\2\2\2\u0096\u0094"+
		"\3\2\2\2\u0097\u0099\3\2\2\2\u0098\u0096\3\2\2\2\u0099\u009a\5\37\20\2"+
		"\u009a\u009b\3\2\2\2\u009b\u009c\b\r\2\2\u009c\32\3\2\2\2\u009d\u009f"+
		"\7/\2\2\u009e\u009d\3\2\2\2\u009e\u009f\3\2\2\2\u009f\u00a0\3\2\2\2\u00a0"+
		"\u00a1\5\35\17\2\u00a1\u00a3\7.\2\2\u00a2\u00a4\t\2\2\2\u00a3\u00a2\3"+
		"\2\2\2\u00a4\u00a5\3\2\2\2\u00a5\u00a3\3\2\2\2\u00a5\u00a6\3\2\2\2\u00a6"+
		"\u00ac\3\2\2\2\u00a7\u00a9\7/\2\2\u00a8\u00a7\3\2\2\2\u00a8\u00a9\3\2"+
		"\2\2\u00a9\u00aa\3\2\2\2\u00aa\u00ac\5\35\17\2\u00ab\u009e\3\2\2\2\u00ab"+
		"\u00a8\3\2\2\2\u00ac\34\3\2\2\2\u00ad\u00b6\7\62\2\2\u00ae\u00b2\t\3\2"+
		"\2\u00af\u00b1\t\2\2\2\u00b0\u00af\3\2\2\2\u00b1\u00b4\3\2\2\2\u00b2\u00b0"+
		"\3\2\2\2\u00b2\u00b3\3\2\2\2\u00b3\u00b6\3\2\2\2\u00b4\u00b2\3\2\2\2\u00b5"+
		"\u00ad\3\2\2\2\u00b5\u00ae\3\2\2\2\u00b6\36\3\2\2\2\u00b7\u00b8\7\f\2"+
		"\2\u00b8 \3\2\2\2\u00b9\u00ba\7\"\2\2\u00ba\"\3\2\2\2\u00bb\u00bc\7<\2"+
		"\2\u00bc\u00bd\7?\2\2\u00bd$\3\2\2\2\u00be\u00bf\7\60\2\2\u00bf&\3\2\2"+
		"\2\u00c0\u00c1\7\60\2\2\u00c1\u00c2\7p\2\2\u00c2\u00c3\7n\2\2\u00c3(\3"+
		"\2\2\2\u00c4\u00c5\7\60\2\2\u00c5\u00c6\7p\2\2\u00c6\u00c7\7n\2\2\u00c7"+
		"\u00c8\7k\2\2\u00c8\u00c9\7d\2\2\u00c9*\3\2\2\2\u00ca\u00cb\7\60\2\2\u00cb"+
		"\u00cc\7\60\2\2\u00cc,\3\2\2\2\u00cd\u00ce\7\61\2\2\u00ce.\3\2\2\2\u00cf"+
		"\u00d0\7]\2\2\u00d0\60\3\2\2\2\u00d1\u00d2\7_\2\2\u00d2\62\3\2\2\2\u00d3"+
		"\u00d4\7~\2\2\u00d4\64\3\2\2\2\u00d5\u00d6\7<\2\2\u00d6\66\3\2\2\2\u00d7"+
		"\u00d8\7.\2\2\u00d8\u00d9\7\"\2\2\u00d98\3\2\2\2\u00da\u00e0\5=\37\2\u00db"+
		"\u00df\5=\37\2\u00dc\u00df\5? \2\u00dd\u00df\5\35\17\2\u00de\u00db\3\2"+
		"\2\2\u00de\u00dc\3\2\2\2\u00de\u00dd\3\2\2\2\u00df\u00e2\3\2\2\2\u00e0"+
		"\u00de\3\2\2\2\u00e0\u00e1\3\2\2\2\u00e1:\3\2\2\2\u00e2\u00e0\3\2\2\2"+
		"\u00e3\u00e9\5? \2\u00e4\u00e8\5=\37\2\u00e5\u00e8\5? \2\u00e6\u00e8\5"+
		"\35\17\2\u00e7\u00e4\3\2\2\2\u00e7\u00e5\3\2\2\2\u00e7\u00e6\3\2\2\2\u00e8"+
		"\u00eb\3\2\2\2\u00e9\u00e7\3\2\2\2\u00e9\u00ea\3\2\2\2\u00ea<\3\2\2\2"+
		"\u00eb\u00e9\3\2\2\2\u00ec\u00ed\t\4\2\2\u00ed>\3\2\2\2\u00ee\u00ef\t"+
		"\5\2\2\u00ef@\3\2\2\2\20\2\u0087\u008d\u0096\u009e\u00a5\u00a8\u00ab\u00b2"+
		"\u00b5\u00de\u00e0\u00e7\u00e9\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}