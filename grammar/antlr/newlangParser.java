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
		T__0=1, SELF=2, TYPE=3, IMPORT=4, ABSTRACT=5, EXTENDS=6, STATIC=7, PRIMITIVE=8, 
		NULL=9, BOOLEAN=10, STRING=11, COMMENT=12, NUMBER=13, NL=14, SPACE=15, 
		ASSIGNATION=16, END=17, FILE_EXTENSION=18, LIBRARY_EXTENSION=19, FOLDER_UP=20, 
		FOLDER_SEPARATOR=21, OPEN_BLOCK=22, CLOSE_BLOCK=23, BLOCK_HEADER_SEPARATOR=24, 
		BLOCK_ARGUMENT_NAME_FINALIZER=25, BLOCK_ARGUMENT_SEPARATOR=26, NAME=27, 
		TYPE_NAME=28, LOWER_CASE=29, UPPER_CASE=30;
	public static final String[] tokenNames = {
		"<INVALID>", "'eval'", "'self'", "'type'", "'import'", "'abstract'", "'extends'", 
		"'static'", "'primitive'", "'null'", "BOOLEAN", "STRING", "COMMENT", "NUMBER", 
		"'\n'", "' '", "':='", "'.'", "'.nl'", "'.nlib'", "'..'", "'/'", "'['", 
		"']'", "'|'", "':'", "', '", "NAME", "TYPE_NAME", "LOWER_CASE", "UPPER_CASE"
	};
	public static final int
		RULE_compilationUnit = 0, RULE_importDeclaration = 1, RULE_folder = 2, 
		RULE_statement = 3, RULE_variableDeclaration = 4, RULE_blockDeclaration = 5, 
		RULE_blockHeader = 6, RULE_blockArgument = 7, RULE_blockArguments = 8, 
		RULE_blockBody = 9, RULE_blockStatement = 10, RULE_blockReturnType = 11, 
		RULE_blockEvaluation = 12, RULE_typeDeclaration = 13, RULE_value = 14, 
		RULE_blockValue = 15;
	public static final String[] ruleNames = {
		"compilationUnit", "importDeclaration", "folder", "statement", "variableDeclaration", 
		"blockDeclaration", "blockHeader", "blockArgument", "blockArguments", 
		"blockBody", "blockStatement", "blockReturnType", "blockEvaluation", "typeDeclaration", 
		"value", "blockValue"
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
			setState(38);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,1,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(33);
					_la = _input.LA(1);
					if (_la==NL) {
						{
						setState(32); match(NL);
						}
					}

					setState(35); importDeclaration();
					}
					} 
				}
				setState(40);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,1,_ctx);
			}
			setState(47);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << TYPE) | (1L << NL) | (1L << OPEN_BLOCK) | (1L << TYPE_NAME))) != 0)) {
				{
				{
				setState(42);
				_la = _input.LA(1);
				if (_la==NL) {
					{
					setState(41); match(NL);
					}
				}

				setState(44); statement();
				}
				}
				setState(49);
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
			setState(50); match(IMPORT);
			setState(51); match(SPACE);
			{
			setState(55);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(52); folder();
					}
					} 
				}
				setState(57);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
			}
			setState(58); match(NAME);
			}
			setState(60);
			_la = _input.LA(1);
			if ( !(_la==FILE_EXTENSION || _la==LIBRARY_EXTENSION) ) {
			_errHandler.recoverInline(this);
			}
			consume();
			setState(61); match(NL);
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
			setState(67);
			switch (_input.LA(1)) {
			case NAME:
				enterOuterAlt(_localctx, 1);
				{
				setState(63); match(NAME);
				setState(64); match(FOLDER_SEPARATOR);
				}
				break;
			case FOLDER_UP:
				enterOuterAlt(_localctx, 2);
				{
				setState(65); match(FOLDER_UP);
				setState(66); match(FOLDER_SEPARATOR);
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
		public TerminalNode NL() { return getToken(newlangParser.NL, 0); }
		public TypeDeclarationContext typeDeclaration() {
			return getRuleContext(TypeDeclarationContext.class,0);
		}
		public BlockDeclarationContext blockDeclaration() {
			return getRuleContext(BlockDeclarationContext.class,0);
		}
		public BlockEvaluationContext blockEvaluation() {
			return getRuleContext(BlockEvaluationContext.class,0);
		}
		public VariableDeclarationContext variableDeclaration() {
			return getRuleContext(VariableDeclarationContext.class,0);
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
			setState(81);
			switch (_input.LA(1)) {
			case TYPE_NAME:
				enterOuterAlt(_localctx, 1);
				{
				setState(69); variableDeclaration();
				setState(70); match(NL);
				}
				break;
			case OPEN_BLOCK:
				enterOuterAlt(_localctx, 2);
				{
				setState(72); blockDeclaration();
				setState(73); match(NL);
				}
				break;
			case T__0:
				enterOuterAlt(_localctx, 3);
				{
				setState(75); blockEvaluation();
				setState(76); match(NL);
				}
				break;
			case TYPE:
				enterOuterAlt(_localctx, 4);
				{
				setState(78); typeDeclaration();
				setState(79); match(NL);
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
			setState(83); match(TYPE_NAME);
			setState(84); match(SPACE);
			setState(85); match(NAME);
			setState(86); match(SPACE);
			setState(87); match(ASSIGNATION);
			setState(88); match(SPACE);
			setState(93);
			switch (_input.LA(1)) {
			case BOOLEAN:
			case STRING:
			case NUMBER:
			case NAME:
			case TYPE_NAME:
				{
				setState(89); value();
				setState(90); match(END);
				}
				break;
			case T__0:
			case OPEN_BLOCK:
				{
				setState(92); blockValue();
				}
				break;
			default:
				throw new NoViableAltException(this);
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

	public static class BlockDeclarationContext extends ParserRuleContext {
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
		public TerminalNode END() { return getToken(newlangParser.END, 0); }
		public TerminalNode SPACE(int i) {
			return getToken(newlangParser.SPACE, i);
		}
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
		enterRule(_localctx, 10, RULE_blockDeclaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(95); match(OPEN_BLOCK);
			setState(96); match(SPACE);
			setState(101);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				{
				setState(97); blockHeader();
				setState(98); match(BLOCK_HEADER_SEPARATOR);
				setState(99);
				_la = _input.LA(1);
				if ( !(_la==NL || _la==SPACE) ) {
				_errHandler.recoverInline(this);
				}
				consume();
				}
				break;
			}
			setState(103); blockBody();
			setState(104);
			_la = _input.LA(1);
			if ( !(_la==NL || _la==SPACE) ) {
			_errHandler.recoverInline(this);
			}
			consume();
			setState(105); match(CLOSE_BLOCK);
			setState(106); match(END);
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
		enterRule(_localctx, 12, RULE_blockHeader);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(111);
			_la = _input.LA(1);
			if (_la==TYPE_NAME) {
				{
				setState(108); blockReturnType();
				setState(109); match(SPACE);
				}
			}

			setState(116);
			_la = _input.LA(1);
			if (_la==NAME) {
				{
				setState(113); blockArguments();
				setState(114); match(SPACE);
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
		public TerminalNode NAME(int i) {
			return getToken(newlangParser.NAME, i);
		}
		public TerminalNode BLOCK_ARGUMENT_NAME_FINALIZER() { return getToken(newlangParser.BLOCK_ARGUMENT_NAME_FINALIZER, 0); }
		public List<TerminalNode> NAME() { return getTokens(newlangParser.NAME); }
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
		enterRule(_localctx, 14, RULE_blockArgument);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(118); match(NAME);
			setState(120);
			_la = _input.LA(1);
			if (_la==BLOCK_ARGUMENT_NAME_FINALIZER) {
				{
				setState(119); match(BLOCK_ARGUMENT_NAME_FINALIZER);
				}
			}

			setState(122); match(SPACE);
			setState(123); match(TYPE_NAME);
			setState(124); match(SPACE);
			setState(125); match(NAME);
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
		enterRule(_localctx, 16, RULE_blockArguments);
		int _la;
		try {
			setState(136);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(127); blockArgument();
				setState(132);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==BLOCK_ARGUMENT_SEPARATOR) {
					{
					{
					setState(128); match(BLOCK_ARGUMENT_SEPARATOR);
					setState(129); blockArgument();
					}
					}
					setState(134);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(135); match(NAME);
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
		enterRule(_localctx, 18, RULE_blockBody);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(142); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(139);
					_la = _input.LA(1);
					if (_la==NL) {
						{
						setState(138); match(NL);
						}
					}

					setState(141); blockStatement();
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(144); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,15,_ctx);
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
		public BlockDeclarationContext blockDeclaration() {
			return getRuleContext(BlockDeclarationContext.class,0);
		}
		public BlockEvaluationContext blockEvaluation() {
			return getRuleContext(BlockEvaluationContext.class,0);
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
		enterRule(_localctx, 20, RULE_blockStatement);
		try {
			setState(149);
			switch (_input.LA(1)) {
			case TYPE_NAME:
				enterOuterAlt(_localctx, 1);
				{
				setState(146); variableDeclaration();
				}
				break;
			case OPEN_BLOCK:
				enterOuterAlt(_localctx, 2);
				{
				setState(147); blockDeclaration();
				}
				break;
			case T__0:
				enterOuterAlt(_localctx, 3);
				{
				setState(148); blockEvaluation();
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
		enterRule(_localctx, 22, RULE_blockReturnType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(151); match(TYPE_NAME);
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
		public TerminalNode END() { return getToken(newlangParser.END, 0); }
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
		enterRule(_localctx, 24, RULE_blockEvaluation);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(153); match(T__0);
			setState(154); match(END);
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
		enterRule(_localctx, 26, RULE_typeDeclaration);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(156); match(TYPE);
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
		enterRule(_localctx, 28, RULE_value);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(158);
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
		enterRule(_localctx, 30, RULE_blockValue);
		try {
			setState(162);
			switch (_input.LA(1)) {
			case T__0:
				enterOuterAlt(_localctx, 1);
				{
				setState(160); blockEvaluation();
				}
				break;
			case OPEN_BLOCK:
				enterOuterAlt(_localctx, 2);
				{
				setState(161); blockDeclaration();
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

	public static final String _serializedATN =
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\3 \u00a7\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\3\2\5\2$\n"+
		"\2\3\2\7\2\'\n\2\f\2\16\2*\13\2\3\2\5\2-\n\2\3\2\7\2\60\n\2\f\2\16\2\63"+
		"\13\2\3\3\3\3\3\3\7\38\n\3\f\3\16\3;\13\3\3\3\3\3\3\3\3\3\3\3\3\4\3\4"+
		"\3\4\3\4\5\4F\n\4\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\5\5"+
		"T\n\5\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\5\6`\n\6\3\7\3\7\3\7\3\7"+
		"\3\7\3\7\5\7h\n\7\3\7\3\7\3\7\3\7\3\7\3\b\3\b\3\b\5\br\n\b\3\b\3\b\3\b"+
		"\5\bw\n\b\3\t\3\t\5\t{\n\t\3\t\3\t\3\t\3\t\3\t\3\n\3\n\3\n\7\n\u0085\n"+
		"\n\f\n\16\n\u0088\13\n\3\n\5\n\u008b\n\n\3\13\5\13\u008e\n\13\3\13\6\13"+
		"\u0091\n\13\r\13\16\13\u0092\3\f\3\f\3\f\5\f\u0098\n\f\3\r\3\r\3\16\3"+
		"\16\3\16\3\17\3\17\3\20\3\20\3\21\3\21\5\21\u00a5\n\21\3\21\2\2\22\2\4"+
		"\6\b\n\f\16\20\22\24\26\30\32\34\36 \2\5\3\2\24\25\3\2\20\21\5\2\f\r\17"+
		"\17\35\36\u00ab\2(\3\2\2\2\4\64\3\2\2\2\6E\3\2\2\2\bS\3\2\2\2\nU\3\2\2"+
		"\2\fa\3\2\2\2\16q\3\2\2\2\20x\3\2\2\2\22\u008a\3\2\2\2\24\u0090\3\2\2"+
		"\2\26\u0097\3\2\2\2\30\u0099\3\2\2\2\32\u009b\3\2\2\2\34\u009e\3\2\2\2"+
		"\36\u00a0\3\2\2\2 \u00a4\3\2\2\2\"$\7\20\2\2#\"\3\2\2\2#$\3\2\2\2$%\3"+
		"\2\2\2%\'\5\4\3\2&#\3\2\2\2\'*\3\2\2\2(&\3\2\2\2()\3\2\2\2)\61\3\2\2\2"+
		"*(\3\2\2\2+-\7\20\2\2,+\3\2\2\2,-\3\2\2\2-.\3\2\2\2.\60\5\b\5\2/,\3\2"+
		"\2\2\60\63\3\2\2\2\61/\3\2\2\2\61\62\3\2\2\2\62\3\3\2\2\2\63\61\3\2\2"+
		"\2\64\65\7\6\2\2\659\7\21\2\2\668\5\6\4\2\67\66\3\2\2\28;\3\2\2\29\67"+
		"\3\2\2\29:\3\2\2\2:<\3\2\2\2;9\3\2\2\2<=\7\35\2\2=>\3\2\2\2>?\t\2\2\2"+
		"?@\7\20\2\2@\5\3\2\2\2AB\7\35\2\2BF\7\27\2\2CD\7\26\2\2DF\7\27\2\2EA\3"+
		"\2\2\2EC\3\2\2\2F\7\3\2\2\2GH\5\n\6\2HI\7\20\2\2IT\3\2\2\2JK\5\f\7\2K"+
		"L\7\20\2\2LT\3\2\2\2MN\5\32\16\2NO\7\20\2\2OT\3\2\2\2PQ\5\34\17\2QR\7"+
		"\20\2\2RT\3\2\2\2SG\3\2\2\2SJ\3\2\2\2SM\3\2\2\2SP\3\2\2\2T\t\3\2\2\2U"+
		"V\7\36\2\2VW\7\21\2\2WX\7\35\2\2XY\7\21\2\2YZ\7\22\2\2Z_\7\21\2\2[\\\5"+
		"\36\20\2\\]\7\23\2\2]`\3\2\2\2^`\5 \21\2_[\3\2\2\2_^\3\2\2\2`\13\3\2\2"+
		"\2ab\7\30\2\2bg\7\21\2\2cd\5\16\b\2de\7\32\2\2ef\t\3\2\2fh\3\2\2\2gc\3"+
		"\2\2\2gh\3\2\2\2hi\3\2\2\2ij\5\24\13\2jk\t\3\2\2kl\7\31\2\2lm\7\23\2\2"+
		"m\r\3\2\2\2no\5\30\r\2op\7\21\2\2pr\3\2\2\2qn\3\2\2\2qr\3\2\2\2rv\3\2"+
		"\2\2st\5\22\n\2tu\7\21\2\2uw\3\2\2\2vs\3\2\2\2vw\3\2\2\2w\17\3\2\2\2x"+
		"z\7\35\2\2y{\7\33\2\2zy\3\2\2\2z{\3\2\2\2{|\3\2\2\2|}\7\21\2\2}~\7\36"+
		"\2\2~\177\7\21\2\2\177\u0080\7\35\2\2\u0080\21\3\2\2\2\u0081\u0086\5\20"+
		"\t\2\u0082\u0083\7\34\2\2\u0083\u0085\5\20\t\2\u0084\u0082\3\2\2\2\u0085"+
		"\u0088\3\2\2\2\u0086\u0084\3\2\2\2\u0086\u0087\3\2\2\2\u0087\u008b\3\2"+
		"\2\2\u0088\u0086\3\2\2\2\u0089\u008b\7\35\2\2\u008a\u0081\3\2\2\2\u008a"+
		"\u0089\3\2\2\2\u008b\23\3\2\2\2\u008c\u008e\7\20\2\2\u008d\u008c\3\2\2"+
		"\2\u008d\u008e\3\2\2\2\u008e\u008f\3\2\2\2\u008f\u0091\5\26\f\2\u0090"+
		"\u008d\3\2\2\2\u0091\u0092\3\2\2\2\u0092\u0090\3\2\2\2\u0092\u0093\3\2"+
		"\2\2\u0093\25\3\2\2\2\u0094\u0098\5\n\6\2\u0095\u0098\5\f\7\2\u0096\u0098"+
		"\5\32\16\2\u0097\u0094\3\2\2\2\u0097\u0095\3\2\2\2\u0097\u0096\3\2\2\2"+
		"\u0098\27\3\2\2\2\u0099\u009a\7\36\2\2\u009a\31\3\2\2\2\u009b\u009c\7"+
		"\3\2\2\u009c\u009d\7\23\2\2\u009d\33\3\2\2\2\u009e\u009f\7\5\2\2\u009f"+
		"\35\3\2\2\2\u00a0\u00a1\t\4\2\2\u00a1\37\3\2\2\2\u00a2\u00a5\5\32\16\2"+
		"\u00a3\u00a5\5\f\7\2\u00a4\u00a2\3\2\2\2\u00a4\u00a3\3\2\2\2\u00a5!\3"+
		"\2\2\2\24#(,\619ES_gqvz\u0086\u008a\u008d\u0092\u0097\u00a4";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}