// Generated from ../newlang.g4 by ANTLR 4.4
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class newlangParser extends Parser {
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
	public static final String[] tokenNames = {
		"<INVALID>", "'&'", "'>'", "'+'", "'-'", "'*'", "'<'", "'='", "'import'", 
		"'self'", "'type'", "'abstract'", "'extends'", "'static'", "'primitive'", 
		"'null'", "BOOLEAN", "STRING", "COMMENT", "NUMBER", "'\n'", "' '", "':='", 
		"'.'", "'.nl'", "'.nlib'", "'..'", "'/'", "'['", "']'", "'|'", "':'", 
		"', '", "'('", "')'", "NAME", "TYPE_NAME", "LOWER_CASE", "UPPER_CASE"
	};
	public static final int
		RULE_compilationUnit = 0, RULE_importDeclaration = 1, RULE_folder = 2, 
		RULE_statement = 3, RULE_variableDeclaration = 4, RULE_block = 5, RULE_blockDeclaration = 6, 
		RULE_blockHeader = 7, RULE_paramBlockName = 8, RULE_blockArgument = 9, 
		RULE_blockArguments = 10, RULE_blockBody = 11, RULE_blockStatement = 12, 
		RULE_blockReturnType = 13, RULE_argsBlockEvaluation = 14, RULE_simpleBlockEvaluation = 15, 
		RULE_blockEvaluation = 16, RULE_typeDeclaration = 17, RULE_value = 18, 
		RULE_blockValue = 19;
	public static final String[] ruleNames = {
		"compilationUnit", "importDeclaration", "folder", "statement", "variableDeclaration", 
		"block", "blockDeclaration", "blockHeader", "paramBlockName", "blockArgument", 
		"blockArguments", "blockBody", "blockStatement", "blockReturnType", "argsBlockEvaluation", 
		"simpleBlockEvaluation", "blockEvaluation", "typeDeclaration", "value", 
		"blockValue"
	};

	@Override
	public String getGrammarFileName() { return "newlang.g4"; }

	@Override
	public String[] getTokenNames() { return tokenNames; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public newlangParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class CompilationUnitContext extends ParserRuleContext {
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public List<TerminalNode> NL() { return getTokens(newlangParser.NL); }
		public List<ImportDeclarationContext> importDeclaration() {
			return getRuleContexts(ImportDeclarationContext.class);
		}
		public TerminalNode NL(int i) {
			return getToken(newlangParser.NL, i);
		}
		public ImportDeclarationContext importDeclaration(int i) {
			return getRuleContext(ImportDeclarationContext.class,i);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public CompilationUnitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_compilationUnit; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).enterCompilationUnit(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).exitCompilationUnit(this);
		}
	}

	public final CompilationUnitContext compilationUnit() throws RecognitionException {
		CompilationUnitContext _localctx = new CompilationUnitContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_compilationUnit);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(46);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,1,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(41);
					_la = _input.LA(1);
					if (_la==NL) {
						{
						setState(40); match(NL);
						}
					}

					setState(43); importDeclaration();
					}
					} 
				}
				setState(48);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,1,_ctx);
			}
			setState(55);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,3,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(50);
					_la = _input.LA(1);
					if (_la==NL) {
						{
						setState(49); match(NL);
						}
					}

					setState(52); statement();
					}
					} 
				}
				setState(57);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,3,_ctx);
			}
			setState(61);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==NL) {
				{
				{
				setState(58); match(NL);
				}
				}
				setState(63);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ImportDeclarationContext extends ParserRuleContext {
		public TerminalNode FILE_EXTENSION() { return getToken(newlangParser.FILE_EXTENSION, 0); }
		public List<FolderContext> folder() {
			return getRuleContexts(FolderContext.class);
		}
		public TerminalNode NL() { return getToken(newlangParser.NL, 0); }
		public FolderContext folder(int i) {
			return getRuleContext(FolderContext.class,i);
		}
		public TerminalNode SPACE() { return getToken(newlangParser.SPACE, 0); }
		public TerminalNode IMPORT() { return getToken(newlangParser.IMPORT, 0); }
		public TerminalNode LIBRARY_EXTENSION() { return getToken(newlangParser.LIBRARY_EXTENSION, 0); }
		public TerminalNode NAME() { return getToken(newlangParser.NAME, 0); }
		public ImportDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_importDeclaration; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).enterImportDeclaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).exitImportDeclaration(this);
		}
	}

	public final ImportDeclarationContext importDeclaration() throws RecognitionException {
		ImportDeclarationContext _localctx = new ImportDeclarationContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_importDeclaration);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(64); match(IMPORT);
			setState(65); match(SPACE);
			{
			setState(69);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(66); folder();
					}
					} 
				}
				setState(71);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
			}
			setState(72); match(NAME);
			}
			setState(74);
			_la = _input.LA(1);
			if ( !(_la==FILE_EXTENSION || _la==LIBRARY_EXTENSION) ) {
			_errHandler.recoverInline(this);
			}
			consume();
			setState(75); match(NL);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FolderContext extends ParserRuleContext {
		public TerminalNode FOLDER_UP() { return getToken(newlangParser.FOLDER_UP, 0); }
		public TerminalNode NAME() { return getToken(newlangParser.NAME, 0); }
		public TerminalNode FOLDER_SEPARATOR() { return getToken(newlangParser.FOLDER_SEPARATOR, 0); }
		public FolderContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_folder; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).enterFolder(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).exitFolder(this);
		}
	}

	public final FolderContext folder() throws RecognitionException {
		FolderContext _localctx = new FolderContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_folder);
		try {
			setState(81);
			switch (_input.LA(1)) {
			case NAME:
				enterOuterAlt(_localctx, 1);
				{
				setState(77); match(NAME);
				setState(78); match(FOLDER_SEPARATOR);
				}
				break;
			case FOLDER_UP:
				enterOuterAlt(_localctx, 2);
				{
				setState(79); match(FOLDER_UP);
				setState(80); match(FOLDER_SEPARATOR);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StatementContext extends ParserRuleContext {
		public BlockStatementContext blockStatement() {
			return getRuleContext(BlockStatementContext.class,0);
		}
		public TerminalNode NL() { return getToken(newlangParser.NL, 0); }
		public TypeDeclarationContext typeDeclaration() {
			return getRuleContext(TypeDeclarationContext.class,0);
		}
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).enterStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).exitStatement(this);
		}
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_statement);
		try {
			setState(89);
			switch (_input.LA(1)) {
			case T__6:
			case T__5:
			case T__4:
			case T__3:
			case T__2:
			case T__1:
			case T__0:
			case SELF:
			case SPACE:
			case FOLDER_SEPARATOR:
			case OPEN_BLOCK:
			case BLOCK_HEADER_SEPARATOR:
			case LPAREN:
			case NAME:
			case TYPE_NAME:
				enterOuterAlt(_localctx, 1);
				{
				setState(83); blockStatement();
				setState(84); match(NL);
				}
				break;
			case TYPE:
				enterOuterAlt(_localctx, 2);
				{
				setState(86); typeDeclaration();
				setState(87); match(NL);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VariableDeclarationContext extends ParserRuleContext {
		public TerminalNode TYPE_NAME() { return getToken(newlangParser.TYPE_NAME, 0); }
		public ValueContext value() {
			return getRuleContext(ValueContext.class,0);
		}
		public List<TerminalNode> SPACE() { return getTokens(newlangParser.SPACE); }
		public TerminalNode NAME() { return getToken(newlangParser.NAME, 0); }
		public TerminalNode ASSIGNATION() { return getToken(newlangParser.ASSIGNATION, 0); }
		public BlockValueContext blockValue() {
			return getRuleContext(BlockValueContext.class,0);
		}
		public TerminalNode END() { return getToken(newlangParser.END, 0); }
		public TerminalNode SPACE(int i) {
			return getToken(newlangParser.SPACE, i);
		}
		public VariableDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variableDeclaration; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).enterVariableDeclaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).exitVariableDeclaration(this);
		}
	}

	public final VariableDeclarationContext variableDeclaration() throws RecognitionException {
		VariableDeclarationContext _localctx = new VariableDeclarationContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_variableDeclaration);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(91); match(TYPE_NAME);
			setState(92); match(SPACE);
			setState(93); match(NAME);
			setState(94); match(SPACE);
			setState(95); match(ASSIGNATION);
			setState(96); match(SPACE);
			setState(101);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				{
				setState(97); value();
				setState(98); match(END);
				}
				break;
			case 2:
				{
				setState(100); blockValue();
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockContext extends ParserRuleContext {
		public List<TerminalNode> NL() { return getTokens(newlangParser.NL); }
		public BlockHeaderContext blockHeader() {
			return getRuleContext(BlockHeaderContext.class,0);
		}
		public TerminalNode NL(int i) {
			return getToken(newlangParser.NL, i);
		}
		public List<TerminalNode> SPACE() { return getTokens(newlangParser.SPACE); }
		public TerminalNode OPEN_BLOCK() { return getToken(newlangParser.OPEN_BLOCK, 0); }
		public TerminalNode CLOSE_BLOCK() { return getToken(newlangParser.CLOSE_BLOCK, 0); }
		public BlockBodyContext blockBody() {
			return getRuleContext(BlockBodyContext.class,0);
		}
		public TerminalNode BLOCK_HEADER_SEPARATOR() { return getToken(newlangParser.BLOCK_HEADER_SEPARATOR, 0); }
		public TerminalNode SPACE(int i) {
			return getToken(newlangParser.SPACE, i);
		}
		public BlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_block; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).enterBlock(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).exitBlock(this);
		}
	}

	public final BlockContext block() throws RecognitionException {
		BlockContext _localctx = new BlockContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_block);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(103); match(OPEN_BLOCK);
			setState(104); match(SPACE);
			setState(109);
			switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
			case 1:
				{
				setState(105); blockHeader();
				setState(106); match(BLOCK_HEADER_SEPARATOR);
				setState(107);
				_la = _input.LA(1);
				if ( !(_la==NL || _la==SPACE) ) {
				_errHandler.recoverInline(this);
				}
				consume();
				}
				break;
			}
			setState(111); blockBody();
			setState(112);
			_la = _input.LA(1);
			if ( !(_la==NL || _la==SPACE) ) {
			_errHandler.recoverInline(this);
			}
			consume();
			setState(113); match(CLOSE_BLOCK);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockDeclarationContext extends ParserRuleContext {
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public TerminalNode END() { return getToken(newlangParser.END, 0); }
		public BlockDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_blockDeclaration; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).enterBlockDeclaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).exitBlockDeclaration(this);
		}
	}

	public final BlockDeclarationContext blockDeclaration() throws RecognitionException {
		BlockDeclarationContext _localctx = new BlockDeclarationContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_blockDeclaration);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(115); block();
			setState(116); match(END);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockHeaderContext extends ParserRuleContext {
		public List<TerminalNode> SPACE() { return getTokens(newlangParser.SPACE); }
		public BlockReturnTypeContext blockReturnType() {
			return getRuleContext(BlockReturnTypeContext.class,0);
		}
		public BlockArgumentsContext blockArguments() {
			return getRuleContext(BlockArgumentsContext.class,0);
		}
		public TerminalNode SPACE(int i) {
			return getToken(newlangParser.SPACE, i);
		}
		public BlockHeaderContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_blockHeader; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).enterBlockHeader(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).exitBlockHeader(this);
		}
	}

	public final BlockHeaderContext blockHeader() throws RecognitionException {
		BlockHeaderContext _localctx = new BlockHeaderContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_blockHeader);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(121);
			_la = _input.LA(1);
			if (_la==TYPE_NAME) {
				{
				setState(118); blockReturnType();
				setState(119); match(SPACE);
				}
			}

			setState(126);
			switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
			case 1:
				{
				setState(123); blockArguments();
				setState(124); match(SPACE);
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ParamBlockNameContext extends ParserRuleContext {
		public TerminalNode NAME() { return getToken(newlangParser.NAME, 0); }
		public TerminalNode COLON() { return getToken(newlangParser.COLON, 0); }
		public ParamBlockNameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_paramBlockName; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).enterParamBlockName(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).exitParamBlockName(this);
		}
	}

	public final ParamBlockNameContext paramBlockName() throws RecognitionException {
		ParamBlockNameContext _localctx = new ParamBlockNameContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_paramBlockName);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(144);
			switch (_input.LA(1)) {
			case NAME:
				{
				setState(128); match(NAME);
				}
				break;
			case T__1:
				{
				setState(129); match(T__1);
				setState(131);
				_la = _input.LA(1);
				if (_la==T__0) {
					{
					setState(130); match(T__0);
					}
				}

				}
				break;
			case T__5:
				{
				setState(133); match(T__5);
				setState(135);
				_la = _input.LA(1);
				if (_la==T__0) {
					{
					setState(134); match(T__0);
					}
				}

				}
				break;
			case T__0:
				{
				setState(137); match(T__0);
				}
				break;
			case BLOCK_HEADER_SEPARATOR:
				{
				setState(138); match(BLOCK_HEADER_SEPARATOR);
				}
				break;
			case T__6:
				{
				setState(139); match(T__6);
				}
				break;
			case T__4:
				{
				setState(140); match(T__4);
				}
				break;
			case T__3:
				{
				setState(141); match(T__3);
				}
				break;
			case T__2:
				{
				setState(142); match(T__2);
				}
				break;
			case FOLDER_SEPARATOR:
				{
				setState(143); match(FOLDER_SEPARATOR);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(147);
			_la = _input.LA(1);
			if (_la==COLON) {
				{
				setState(146); match(COLON);
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockArgumentContext extends ParserRuleContext {
		public TerminalNode TYPE_NAME() { return getToken(newlangParser.TYPE_NAME, 0); }
		public List<TerminalNode> SPACE() { return getTokens(newlangParser.SPACE); }
		public ParamBlockNameContext paramBlockName() {
			return getRuleContext(ParamBlockNameContext.class,0);
		}
		public TerminalNode NAME() { return getToken(newlangParser.NAME, 0); }
		public TerminalNode SPACE(int i) {
			return getToken(newlangParser.SPACE, i);
		}
		public BlockArgumentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_blockArgument; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).enterBlockArgument(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).exitBlockArgument(this);
		}
	}

	public final BlockArgumentContext blockArgument() throws RecognitionException {
		BlockArgumentContext _localctx = new BlockArgumentContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_blockArgument);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(149); paramBlockName();
			setState(150); match(SPACE);
			setState(151); match(TYPE_NAME);
			setState(152); match(SPACE);
			setState(153); match(NAME);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockArgumentsContext extends ParserRuleContext {
		public List<TerminalNode> BLOCK_ARGUMENT_SEPARATOR() { return getTokens(newlangParser.BLOCK_ARGUMENT_SEPARATOR); }
		public TerminalNode BLOCK_ARGUMENT_SEPARATOR(int i) {
			return getToken(newlangParser.BLOCK_ARGUMENT_SEPARATOR, i);
		}
		public TerminalNode NAME() { return getToken(newlangParser.NAME, 0); }
		public BlockArgumentContext blockArgument(int i) {
			return getRuleContext(BlockArgumentContext.class,i);
		}
		public List<BlockArgumentContext> blockArgument() {
			return getRuleContexts(BlockArgumentContext.class);
		}
		public BlockArgumentsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_blockArguments; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).enterBlockArguments(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).exitBlockArguments(this);
		}
	}

	public final BlockArgumentsContext blockArguments() throws RecognitionException {
		BlockArgumentsContext _localctx = new BlockArgumentsContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_blockArguments);
		int _la;
		try {
			setState(164);
			switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(155); blockArgument();
				setState(160);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==BLOCK_ARGUMENT_SEPARATOR) {
					{
					{
					setState(156); match(BLOCK_ARGUMENT_SEPARATOR);
					setState(157); blockArgument();
					}
					}
					setState(162);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(163); match(NAME);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockBodyContext extends ParserRuleContext {
		public List<BlockStatementContext> blockStatement() {
			return getRuleContexts(BlockStatementContext.class);
		}
		public List<TerminalNode> NL() { return getTokens(newlangParser.NL); }
		public TerminalNode NL(int i) {
			return getToken(newlangParser.NL, i);
		}
		public BlockStatementContext blockStatement(int i) {
			return getRuleContext(BlockStatementContext.class,i);
		}
		public BlockBodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_blockBody; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).enterBlockBody(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).exitBlockBody(this);
		}
	}

	public final BlockBodyContext blockBody() throws RecognitionException {
		BlockBodyContext _localctx = new BlockBodyContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_blockBody);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(170); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(167);
					_la = _input.LA(1);
					if (_la==NL) {
						{
						setState(166); match(NL);
						}
					}

					setState(169); blockStatement();
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(172); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,19,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockStatementContext extends ParserRuleContext {
		public List<TerminalNode> SPACE() { return getTokens(newlangParser.SPACE); }
		public BlockDeclarationContext blockDeclaration() {
			return getRuleContext(BlockDeclarationContext.class,0);
		}
		public TerminalNode END() { return getToken(newlangParser.END, 0); }
		public BlockEvaluationContext blockEvaluation() {
			return getRuleContext(BlockEvaluationContext.class,0);
		}
		public TerminalNode SPACE(int i) {
			return getToken(newlangParser.SPACE, i);
		}
		public VariableDeclarationContext variableDeclaration() {
			return getRuleContext(VariableDeclarationContext.class,0);
		}
		public BlockStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_blockStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).enterBlockStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).exitBlockStatement(this);
		}
	}

	public final BlockStatementContext blockStatement() throws RecognitionException {
		BlockStatementContext _localctx = new BlockStatementContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_blockStatement);
		int _la;
		try {
			setState(197);
			switch ( getInterpreter().adaptivePredict(_input,23,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(177);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==SPACE) {
					{
					{
					setState(174); match(SPACE);
					}
					}
					setState(179);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(180); variableDeclaration();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(184);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==SPACE) {
					{
					{
					setState(181); match(SPACE);
					}
					}
					setState(186);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(187); blockDeclaration();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(191);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==SPACE) {
					{
					{
					setState(188); match(SPACE);
					}
					}
					setState(193);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(194); blockEvaluation();
				setState(195); match(END);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockReturnTypeContext extends ParserRuleContext {
		public TerminalNode TYPE_NAME() { return getToken(newlangParser.TYPE_NAME, 0); }
		public BlockReturnTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_blockReturnType; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).enterBlockReturnType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).exitBlockReturnType(this);
		}
	}

	public final BlockReturnTypeContext blockReturnType() throws RecognitionException {
		BlockReturnTypeContext _localctx = new BlockReturnTypeContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_blockReturnType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(199); match(TYPE_NAME);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ArgsBlockEvaluationContext extends ParserRuleContext {
		public ValueContext value() {
			return getRuleContext(ValueContext.class,0);
		}
		public TerminalNode SPACE() { return getToken(newlangParser.SPACE, 0); }
		public ParamBlockNameContext paramBlockName() {
			return getRuleContext(ParamBlockNameContext.class,0);
		}
		public ArgsBlockEvaluationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_argsBlockEvaluation; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).enterArgsBlockEvaluation(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).exitArgsBlockEvaluation(this);
		}
	}

	public final ArgsBlockEvaluationContext argsBlockEvaluation() throws RecognitionException {
		ArgsBlockEvaluationContext _localctx = new ArgsBlockEvaluationContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_argsBlockEvaluation);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(201); paramBlockName();
			setState(202); match(SPACE);
			setState(203); value();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SimpleBlockEvaluationContext extends ParserRuleContext {
		public List<TerminalNode> SPACE() { return getTokens(newlangParser.SPACE); }
		public TerminalNode NAME() { return getToken(newlangParser.NAME, 0); }
		public List<ArgsBlockEvaluationContext> argsBlockEvaluation() {
			return getRuleContexts(ArgsBlockEvaluationContext.class);
		}
		public TerminalNode SPACE(int i) {
			return getToken(newlangParser.SPACE, i);
		}
		public ArgsBlockEvaluationContext argsBlockEvaluation(int i) {
			return getRuleContext(ArgsBlockEvaluationContext.class,i);
		}
		public SimpleBlockEvaluationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simpleBlockEvaluation; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).enterSimpleBlockEvaluation(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).exitSimpleBlockEvaluation(this);
		}
	}

	public final SimpleBlockEvaluationContext simpleBlockEvaluation() throws RecognitionException {
		SimpleBlockEvaluationContext _localctx = new SimpleBlockEvaluationContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_simpleBlockEvaluation);
		int _la;
		try {
			setState(214);
			switch ( getInterpreter().adaptivePredict(_input,25,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(205); match(NAME);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(206); argsBlockEvaluation();
				setState(211);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==SPACE) {
					{
					{
					setState(207); match(SPACE);
					setState(208); argsBlockEvaluation();
					}
					}
					setState(213);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockEvaluationContext extends ParserRuleContext {
		public TerminalNode TYPE_NAME() { return getToken(newlangParser.TYPE_NAME, 0); }
		public TerminalNode SPACE() { return getToken(newlangParser.SPACE, 0); }
		public BlockEvaluationContext blockEvaluation(int i) {
			return getRuleContext(BlockEvaluationContext.class,i);
		}
		public TerminalNode SELF() { return getToken(newlangParser.SELF, 0); }
		public TerminalNode RPAREN() { return getToken(newlangParser.RPAREN, 0); }
		public TerminalNode NAME() { return getToken(newlangParser.NAME, 0); }
		public SimpleBlockEvaluationContext simpleBlockEvaluation() {
			return getRuleContext(SimpleBlockEvaluationContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public TerminalNode LPAREN() { return getToken(newlangParser.LPAREN, 0); }
		public List<BlockEvaluationContext> blockEvaluation() {
			return getRuleContexts(BlockEvaluationContext.class);
		}
		public BlockEvaluationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_blockEvaluation; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).enterBlockEvaluation(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).exitBlockEvaluation(this);
		}
	}

	public final BlockEvaluationContext blockEvaluation() throws RecognitionException {
		BlockEvaluationContext _localctx = new BlockEvaluationContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_blockEvaluation);
		try {
			setState(230);
			switch ( getInterpreter().adaptivePredict(_input,27,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(216); match(LPAREN);
				setState(217); blockEvaluation();
				setState(218); match(RPAREN);
				setState(219); blockEvaluation();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(225);
				switch (_input.LA(1)) {
				case TYPE_NAME:
					{
					setState(221); match(TYPE_NAME);
					}
					break;
				case NAME:
					{
					setState(222); match(NAME);
					}
					break;
				case SELF:
					{
					setState(223); match(SELF);
					}
					break;
				case OPEN_BLOCK:
					{
					setState(224); block();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(227); match(SPACE);
				setState(228); simpleBlockEvaluation();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(229); simpleBlockEvaluation();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypeDeclarationContext extends ParserRuleContext {
		public TypeDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeDeclaration; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).enterTypeDeclaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).exitTypeDeclaration(this);
		}
	}

	public final TypeDeclarationContext typeDeclaration() throws RecognitionException {
		TypeDeclarationContext _localctx = new TypeDeclarationContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_typeDeclaration);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(232); match(TYPE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ValueContext extends ParserRuleContext {
		public TerminalNode TYPE_NAME() { return getToken(newlangParser.TYPE_NAME, 0); }
		public TerminalNode BOOLEAN() { return getToken(newlangParser.BOOLEAN, 0); }
		public TerminalNode NAME() { return getToken(newlangParser.NAME, 0); }
		public TerminalNode NUMBER() { return getToken(newlangParser.NUMBER, 0); }
		public TerminalNode STRING() { return getToken(newlangParser.STRING, 0); }
		public ValueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_value; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).enterValue(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).exitValue(this);
		}
	}

	public final ValueContext value() throws RecognitionException {
		ValueContext _localctx = new ValueContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_value);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(234);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << BOOLEAN) | (1L << STRING) | (1L << NUMBER) | (1L << NAME) | (1L << TYPE_NAME))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			consume();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockValueContext extends ParserRuleContext {
		public BlockDeclarationContext blockDeclaration() {
			return getRuleContext(BlockDeclarationContext.class,0);
		}
		public TerminalNode END() { return getToken(newlangParser.END, 0); }
		public BlockEvaluationContext blockEvaluation() {
			return getRuleContext(BlockEvaluationContext.class,0);
		}
		public BlockValueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_blockValue; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).enterBlockValue(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof newlangListener ) ((newlangListener)listener).exitBlockValue(this);
		}
	}

	public final BlockValueContext blockValue() throws RecognitionException {
		BlockValueContext _localctx = new BlockValueContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_blockValue);
		try {
			setState(240);
			switch ( getInterpreter().adaptivePredict(_input,28,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(236); blockEvaluation();
				setState(237); match(END);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(239); blockDeclaration();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\3(\u00f5\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\3\2\5\2,\n\2\3\2\7\2/\n\2\f\2\16\2\62\13"+
		"\2\3\2\5\2\65\n\2\3\2\7\28\n\2\f\2\16\2;\13\2\3\2\7\2>\n\2\f\2\16\2A\13"+
		"\2\3\3\3\3\3\3\7\3F\n\3\f\3\16\3I\13\3\3\3\3\3\3\3\3\3\3\3\3\4\3\4\3\4"+
		"\3\4\5\4T\n\4\3\5\3\5\3\5\3\5\3\5\3\5\5\5\\\n\5\3\6\3\6\3\6\3\6\3\6\3"+
		"\6\3\6\3\6\3\6\3\6\5\6h\n\6\3\7\3\7\3\7\3\7\3\7\3\7\5\7p\n\7\3\7\3\7\3"+
		"\7\3\7\3\b\3\b\3\b\3\t\3\t\3\t\5\t|\n\t\3\t\3\t\3\t\5\t\u0081\n\t\3\n"+
		"\3\n\3\n\5\n\u0086\n\n\3\n\3\n\5\n\u008a\n\n\3\n\3\n\3\n\3\n\3\n\3\n\3"+
		"\n\5\n\u0093\n\n\3\n\5\n\u0096\n\n\3\13\3\13\3\13\3\13\3\13\3\13\3\f\3"+
		"\f\3\f\7\f\u00a1\n\f\f\f\16\f\u00a4\13\f\3\f\5\f\u00a7\n\f\3\r\5\r\u00aa"+
		"\n\r\3\r\6\r\u00ad\n\r\r\r\16\r\u00ae\3\16\7\16\u00b2\n\16\f\16\16\16"+
		"\u00b5\13\16\3\16\3\16\7\16\u00b9\n\16\f\16\16\16\u00bc\13\16\3\16\3\16"+
		"\7\16\u00c0\n\16\f\16\16\16\u00c3\13\16\3\16\3\16\3\16\5\16\u00c8\n\16"+
		"\3\17\3\17\3\20\3\20\3\20\3\20\3\21\3\21\3\21\3\21\7\21\u00d4\n\21\f\21"+
		"\16\21\u00d7\13\21\5\21\u00d9\n\21\3\22\3\22\3\22\3\22\3\22\3\22\3\22"+
		"\3\22\3\22\5\22\u00e4\n\22\3\22\3\22\3\22\5\22\u00e9\n\22\3\23\3\23\3"+
		"\24\3\24\3\25\3\25\3\25\3\25\5\25\u00f3\n\25\3\25\2\2\26\2\4\6\b\n\f\16"+
		"\20\22\24\26\30\32\34\36 \"$&(\2\5\3\2\32\33\3\2\26\27\5\2\22\23\25\25"+
		"%&\u0109\2\60\3\2\2\2\4B\3\2\2\2\6S\3\2\2\2\b[\3\2\2\2\n]\3\2\2\2\fi\3"+
		"\2\2\2\16u\3\2\2\2\20{\3\2\2\2\22\u0092\3\2\2\2\24\u0097\3\2\2\2\26\u00a6"+
		"\3\2\2\2\30\u00ac\3\2\2\2\32\u00c7\3\2\2\2\34\u00c9\3\2\2\2\36\u00cb\3"+
		"\2\2\2 \u00d8\3\2\2\2\"\u00e8\3\2\2\2$\u00ea\3\2\2\2&\u00ec\3\2\2\2(\u00f2"+
		"\3\2\2\2*,\7\26\2\2+*\3\2\2\2+,\3\2\2\2,-\3\2\2\2-/\5\4\3\2.+\3\2\2\2"+
		"/\62\3\2\2\2\60.\3\2\2\2\60\61\3\2\2\2\619\3\2\2\2\62\60\3\2\2\2\63\65"+
		"\7\26\2\2\64\63\3\2\2\2\64\65\3\2\2\2\65\66\3\2\2\2\668\5\b\5\2\67\64"+
		"\3\2\2\28;\3\2\2\29\67\3\2\2\29:\3\2\2\2:?\3\2\2\2;9\3\2\2\2<>\7\26\2"+
		"\2=<\3\2\2\2>A\3\2\2\2?=\3\2\2\2?@\3\2\2\2@\3\3\2\2\2A?\3\2\2\2BC\7\n"+
		"\2\2CG\7\27\2\2DF\5\6\4\2ED\3\2\2\2FI\3\2\2\2GE\3\2\2\2GH\3\2\2\2HJ\3"+
		"\2\2\2IG\3\2\2\2JK\7%\2\2KL\3\2\2\2LM\t\2\2\2MN\7\26\2\2N\5\3\2\2\2OP"+
		"\7%\2\2PT\7\35\2\2QR\7\34\2\2RT\7\35\2\2SO\3\2\2\2SQ\3\2\2\2T\7\3\2\2"+
		"\2UV\5\32\16\2VW\7\26\2\2W\\\3\2\2\2XY\5$\23\2YZ\7\26\2\2Z\\\3\2\2\2["+
		"U\3\2\2\2[X\3\2\2\2\\\t\3\2\2\2]^\7&\2\2^_\7\27\2\2_`\7%\2\2`a\7\27\2"+
		"\2ab\7\30\2\2bg\7\27\2\2cd\5&\24\2de\7\31\2\2eh\3\2\2\2fh\5(\25\2gc\3"+
		"\2\2\2gf\3\2\2\2h\13\3\2\2\2ij\7\36\2\2jo\7\27\2\2kl\5\20\t\2lm\7 \2\2"+
		"mn\t\3\2\2np\3\2\2\2ok\3\2\2\2op\3\2\2\2pq\3\2\2\2qr\5\30\r\2rs\t\3\2"+
		"\2st\7\37\2\2t\r\3\2\2\2uv\5\f\7\2vw\7\31\2\2w\17\3\2\2\2xy\5\34\17\2"+
		"yz\7\27\2\2z|\3\2\2\2{x\3\2\2\2{|\3\2\2\2|\u0080\3\2\2\2}~\5\26\f\2~\177"+
		"\7\27\2\2\177\u0081\3\2\2\2\u0080}\3\2\2\2\u0080\u0081\3\2\2\2\u0081\21"+
		"\3\2\2\2\u0082\u0093\7%\2\2\u0083\u0085\7\b\2\2\u0084\u0086\7\t\2\2\u0085"+
		"\u0084\3\2\2\2\u0085\u0086\3\2\2\2\u0086\u0093\3\2\2\2\u0087\u0089\7\4"+
		"\2\2\u0088\u008a\7\t\2\2\u0089\u0088\3\2\2\2\u0089\u008a\3\2\2\2\u008a"+
		"\u0093\3\2\2\2\u008b\u0093\7\t\2\2\u008c\u0093\7 \2\2\u008d\u0093\7\3"+
		"\2\2\u008e\u0093\7\5\2\2\u008f\u0093\7\6\2\2\u0090\u0093\7\7\2\2\u0091"+
		"\u0093\7\35\2\2\u0092\u0082\3\2\2\2\u0092\u0083\3\2\2\2\u0092\u0087\3"+
		"\2\2\2\u0092\u008b\3\2\2\2\u0092\u008c\3\2\2\2\u0092\u008d\3\2\2\2\u0092"+
		"\u008e\3\2\2\2\u0092\u008f\3\2\2\2\u0092\u0090\3\2\2\2\u0092\u0091\3\2"+
		"\2\2\u0093\u0095\3\2\2\2\u0094\u0096\7!\2\2\u0095\u0094\3\2\2\2\u0095"+
		"\u0096\3\2\2\2\u0096\23\3\2\2\2\u0097\u0098\5\22\n\2\u0098\u0099\7\27"+
		"\2\2\u0099\u009a\7&\2\2\u009a\u009b\7\27\2\2\u009b\u009c\7%\2\2\u009c"+
		"\25\3\2\2\2\u009d\u00a2\5\24\13\2\u009e\u009f\7\"\2\2\u009f\u00a1\5\24"+
		"\13\2\u00a0\u009e\3\2\2\2\u00a1\u00a4\3\2\2\2\u00a2\u00a0\3\2\2\2\u00a2"+
		"\u00a3\3\2\2\2\u00a3\u00a7\3\2\2\2\u00a4\u00a2\3\2\2\2\u00a5\u00a7\7%"+
		"\2\2\u00a6\u009d\3\2\2\2\u00a6\u00a5\3\2\2\2\u00a7\27\3\2\2\2\u00a8\u00aa"+
		"\7\26\2\2\u00a9\u00a8\3\2\2\2\u00a9\u00aa\3\2\2\2\u00aa\u00ab\3\2\2\2"+
		"\u00ab\u00ad\5\32\16\2\u00ac\u00a9\3\2\2\2\u00ad\u00ae\3\2\2\2\u00ae\u00ac"+
		"\3\2\2\2\u00ae\u00af\3\2\2\2\u00af\31\3\2\2\2\u00b0\u00b2\7\27\2\2\u00b1"+
		"\u00b0\3\2\2\2\u00b2\u00b5\3\2\2\2\u00b3\u00b1\3\2\2\2\u00b3\u00b4\3\2"+
		"\2\2\u00b4\u00b6\3\2\2\2\u00b5\u00b3\3\2\2\2\u00b6\u00c8\5\n\6\2\u00b7"+
		"\u00b9\7\27\2\2\u00b8\u00b7\3\2\2\2\u00b9\u00bc\3\2\2\2\u00ba\u00b8\3"+
		"\2\2\2\u00ba\u00bb\3\2\2\2\u00bb\u00bd\3\2\2\2\u00bc\u00ba\3\2\2\2\u00bd"+
		"\u00c8\5\16\b\2\u00be\u00c0\7\27\2\2\u00bf\u00be\3\2\2\2\u00c0\u00c3\3"+
		"\2\2\2\u00c1\u00bf\3\2\2\2\u00c1\u00c2\3\2\2\2\u00c2\u00c4\3\2\2\2\u00c3"+
		"\u00c1\3\2\2\2\u00c4\u00c5\5\"\22\2\u00c5\u00c6\7\31\2\2\u00c6\u00c8\3"+
		"\2\2\2\u00c7\u00b3\3\2\2\2\u00c7\u00ba\3\2\2\2\u00c7\u00c1\3\2\2\2\u00c8"+
		"\33\3\2\2\2\u00c9\u00ca\7&\2\2\u00ca\35\3\2\2\2\u00cb\u00cc\5\22\n\2\u00cc"+
		"\u00cd\7\27\2\2\u00cd\u00ce\5&\24\2\u00ce\37\3\2\2\2\u00cf\u00d9\7%\2"+
		"\2\u00d0\u00d5\5\36\20\2\u00d1\u00d2\7\27\2\2\u00d2\u00d4\5\36\20\2\u00d3"+
		"\u00d1\3\2\2\2\u00d4\u00d7\3\2\2\2\u00d5\u00d3\3\2\2\2\u00d5\u00d6\3\2"+
		"\2\2\u00d6\u00d9\3\2\2\2\u00d7\u00d5\3\2\2\2\u00d8\u00cf\3\2\2\2\u00d8"+
		"\u00d0\3\2\2\2\u00d9!\3\2\2\2\u00da\u00db\7#\2\2\u00db\u00dc\5\"\22\2"+
		"\u00dc\u00dd\7$\2\2\u00dd\u00de\5\"\22\2\u00de\u00e9\3\2\2\2\u00df\u00e4"+
		"\7&\2\2\u00e0\u00e4\7%\2\2\u00e1\u00e4\7\13\2\2\u00e2\u00e4\5\f\7\2\u00e3"+
		"\u00df\3\2\2\2\u00e3\u00e0\3\2\2\2\u00e3\u00e1\3\2\2\2\u00e3\u00e2\3\2"+
		"\2\2\u00e4\u00e5\3\2\2\2\u00e5\u00e6\7\27\2\2\u00e6\u00e9\5 \21\2\u00e7"+
		"\u00e9\5 \21\2\u00e8\u00da\3\2\2\2\u00e8\u00e3\3\2\2\2\u00e8\u00e7\3\2"+
		"\2\2\u00e9#\3\2\2\2\u00ea\u00eb\7\f\2\2\u00eb%\3\2\2\2\u00ec\u00ed\t\4"+
		"\2\2\u00ed\'\3\2\2\2\u00ee\u00ef\5\"\22\2\u00ef\u00f0\7\31\2\2\u00f0\u00f3"+
		"\3\2\2\2\u00f1\u00f3\5\16\b\2\u00f2\u00ee\3\2\2\2\u00f2\u00f1\3\2\2\2"+
		"\u00f3)\3\2\2\2\37+\60\649?GS[go{\u0080\u0085\u0089\u0092\u0095\u00a2"+
		"\u00a6\u00a9\u00ae\u00b3\u00ba\u00c1\u00c7\u00d5\u00d8\u00e3\u00e8\u00f2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}