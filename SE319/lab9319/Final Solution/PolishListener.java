// Generated from Polish.g4 by ANTLR 4.5.3

   import java.util.Stack;

import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link PolishParser}.
 */
public interface PolishListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link PolishParser#start}.
	 * @param ctx the parse tree
	 */
	void enterStart(PolishParser.StartContext ctx);
	/**
	 * Exit a parse tree produced by {@link PolishParser#start}.
	 * @param ctx the parse tree
	 */
	void exitStart(PolishParser.StartContext ctx);
	/**
	 * Enter a parse tree produced by {@link PolishParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr(PolishParser.ExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link PolishParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr(PolishParser.ExprContext ctx);
}