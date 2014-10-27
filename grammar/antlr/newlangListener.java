// Generated from ../newlang.g4 by ANTLR 4.4
import org.antlr.v4.runtime.misc.NotNull;
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link newlangParser}.
 */
public interface newlangListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link newlangParser#blockArguments}.
	 * @param ctx the parse tree
	 */
	void enterBlockArguments(@NotNull newlangParser.BlockArgumentsContext ctx);
	/**
	 * Exit a parse tree produced by {@link newlangParser#blockArguments}.
	 * @param ctx the parse tree
	 */
	void exitBlockArguments(@NotNull newlangParser.BlockArgumentsContext ctx);
	/**
	 * Enter a parse tree produced by {@link newlangParser#compilationUnit}.
	 * @param ctx the parse tree
	 */
	void enterCompilationUnit(@NotNull newlangParser.CompilationUnitContext ctx);
	/**
	 * Exit a parse tree produced by {@link newlangParser#compilationUnit}.
	 * @param ctx the parse tree
	 */
	void exitCompilationUnit(@NotNull newlangParser.CompilationUnitContext ctx);
	/**
	 * Enter a parse tree produced by {@link newlangParser#block}.
	 * @param ctx the parse tree
	 */
	void enterBlock(@NotNull newlangParser.BlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link newlangParser#block}.
	 * @param ctx the parse tree
	 */
	void exitBlock(@NotNull newlangParser.BlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link newlangParser#blockStatement}.
	 * @param ctx the parse tree
	 */
	void enterBlockStatement(@NotNull newlangParser.BlockStatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link newlangParser#blockStatement}.
	 * @param ctx the parse tree
	 */
	void exitBlockStatement(@NotNull newlangParser.BlockStatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link newlangParser#typeDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterTypeDeclaration(@NotNull newlangParser.TypeDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link newlangParser#typeDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitTypeDeclaration(@NotNull newlangParser.TypeDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link newlangParser#blockValue}.
	 * @param ctx the parse tree
	 */
	void enterBlockValue(@NotNull newlangParser.BlockValueContext ctx);
	/**
	 * Exit a parse tree produced by {@link newlangParser#blockValue}.
	 * @param ctx the parse tree
	 */
	void exitBlockValue(@NotNull newlangParser.BlockValueContext ctx);
	/**
	 * Enter a parse tree produced by {@link newlangParser#blockReturnType}.
	 * @param ctx the parse tree
	 */
	void enterBlockReturnType(@NotNull newlangParser.BlockReturnTypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link newlangParser#blockReturnType}.
	 * @param ctx the parse tree
	 */
	void exitBlockReturnType(@NotNull newlangParser.BlockReturnTypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link newlangParser#folder}.
	 * @param ctx the parse tree
	 */
	void enterFolder(@NotNull newlangParser.FolderContext ctx);
	/**
	 * Exit a parse tree produced by {@link newlangParser#folder}.
	 * @param ctx the parse tree
	 */
	void exitFolder(@NotNull newlangParser.FolderContext ctx);
	/**
	 * Enter a parse tree produced by {@link newlangParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatement(@NotNull newlangParser.StatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link newlangParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatement(@NotNull newlangParser.StatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link newlangParser#variableDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterVariableDeclaration(@NotNull newlangParser.VariableDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link newlangParser#variableDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitVariableDeclaration(@NotNull newlangParser.VariableDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link newlangParser#blockDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterBlockDeclaration(@NotNull newlangParser.BlockDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link newlangParser#blockDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitBlockDeclaration(@NotNull newlangParser.BlockDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link newlangParser#blockArgument}.
	 * @param ctx the parse tree
	 */
	void enterBlockArgument(@NotNull newlangParser.BlockArgumentContext ctx);
	/**
	 * Exit a parse tree produced by {@link newlangParser#blockArgument}.
	 * @param ctx the parse tree
	 */
	void exitBlockArgument(@NotNull newlangParser.BlockArgumentContext ctx);
	/**
	 * Enter a parse tree produced by {@link newlangParser#value}.
	 * @param ctx the parse tree
	 */
	void enterValue(@NotNull newlangParser.ValueContext ctx);
	/**
	 * Exit a parse tree produced by {@link newlangParser#value}.
	 * @param ctx the parse tree
	 */
	void exitValue(@NotNull newlangParser.ValueContext ctx);
	/**
	 * Enter a parse tree produced by {@link newlangParser#argsBlockEvaluation}.
	 * @param ctx the parse tree
	 */
	void enterArgsBlockEvaluation(@NotNull newlangParser.ArgsBlockEvaluationContext ctx);
	/**
	 * Exit a parse tree produced by {@link newlangParser#argsBlockEvaluation}.
	 * @param ctx the parse tree
	 */
	void exitArgsBlockEvaluation(@NotNull newlangParser.ArgsBlockEvaluationContext ctx);
	/**
	 * Enter a parse tree produced by {@link newlangParser#paramBlockName}.
	 * @param ctx the parse tree
	 */
	void enterParamBlockName(@NotNull newlangParser.ParamBlockNameContext ctx);
	/**
	 * Exit a parse tree produced by {@link newlangParser#paramBlockName}.
	 * @param ctx the parse tree
	 */
	void exitParamBlockName(@NotNull newlangParser.ParamBlockNameContext ctx);
	/**
	 * Enter a parse tree produced by {@link newlangParser#blockEvaluation}.
	 * @param ctx the parse tree
	 */
	void enterBlockEvaluation(@NotNull newlangParser.BlockEvaluationContext ctx);
	/**
	 * Exit a parse tree produced by {@link newlangParser#blockEvaluation}.
	 * @param ctx the parse tree
	 */
	void exitBlockEvaluation(@NotNull newlangParser.BlockEvaluationContext ctx);
	/**
	 * Enter a parse tree produced by {@link newlangParser#simpleBlockEvaluation}.
	 * @param ctx the parse tree
	 */
	void enterSimpleBlockEvaluation(@NotNull newlangParser.SimpleBlockEvaluationContext ctx);
	/**
	 * Exit a parse tree produced by {@link newlangParser#simpleBlockEvaluation}.
	 * @param ctx the parse tree
	 */
	void exitSimpleBlockEvaluation(@NotNull newlangParser.SimpleBlockEvaluationContext ctx);
	/**
	 * Enter a parse tree produced by {@link newlangParser#importDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterImportDeclaration(@NotNull newlangParser.ImportDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link newlangParser#importDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitImportDeclaration(@NotNull newlangParser.ImportDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link newlangParser#blockHeader}.
	 * @param ctx the parse tree
	 */
	void enterBlockHeader(@NotNull newlangParser.BlockHeaderContext ctx);
	/**
	 * Exit a parse tree produced by {@link newlangParser#blockHeader}.
	 * @param ctx the parse tree
	 */
	void exitBlockHeader(@NotNull newlangParser.BlockHeaderContext ctx);
	/**
	 * Enter a parse tree produced by {@link newlangParser#blockBody}.
	 * @param ctx the parse tree
	 */
	void enterBlockBody(@NotNull newlangParser.BlockBodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link newlangParser#blockBody}.
	 * @param ctx the parse tree
	 */
	void exitBlockBody(@NotNull newlangParser.BlockBodyContext ctx);
}