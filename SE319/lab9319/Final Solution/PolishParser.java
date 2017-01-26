// Generated from Polish.g4 by ANTLR 4.5.3

   import java.util.Stack;

import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class PolishParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.5.3", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		VAL=1, OPP=2, END=3, WS=4;
	public static final int
		RULE_start = 0, RULE_expr = 1;
	public static final String[] ruleNames = {
		"start", "expr"
	};

	private static final String[] _LITERAL_NAMES = {
		null, null, null, "';'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "VAL", "OPP", "END", "WS"
	};
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "Polish.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }


	Stack<String> vals=new Stack<String>();
	Boolean error=false;

	public PolishParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class StartContext extends ParserRuleContext {
		public List<TerminalNode> END() { return getTokens(PolishParser.END); }
		public TerminalNode END(int i) {
			return getToken(PolishParser.END, i);
		}
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public StartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_start; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PolishListener ) ((PolishListener)listener).enterStart(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PolishListener ) ((PolishListener)listener).exitStart(this);
		}
	}

	public final StartContext start() throws RecognitionException {
		StartContext _localctx = new StartContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_start);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(12); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(7);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==VAL) {
					{
					{
					setState(4);
					expr();
					}
					}
					setState(9);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(10);
				match(END);

				         if(vals.empty())
				         {
				            System.out.print("INVALID EXPRESSION;");
				         }
				         else
				         {
				            String temp=vals.pop();
				            if(vals.empty())
				            {
				               System.out.print(temp+";");
				            }
				            else
				            {
				               System.out.print("INVALID EXPRESSION;");
				            }
				         }
				         vals=new Stack<String>();
				         error=false;
				      
				}
				}
				setState(14); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==VAL || _la==END );
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

	public static class ExprContext extends ParserRuleContext {
		public Token VAL;
		public Token OPP;
		public List<TerminalNode> VAL() { return getTokens(PolishParser.VAL); }
		public TerminalNode VAL(int i) {
			return getToken(PolishParser.VAL, i);
		}
		public List<TerminalNode> OPP() { return getTokens(PolishParser.OPP); }
		public TerminalNode OPP(int i) {
			return getToken(PolishParser.OPP, i);
		}
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof PolishListener ) ((PolishListener)listener).enterExpr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof PolishListener ) ((PolishListener)listener).exitExpr(this);
		}
	}

	public final ExprContext expr() throws RecognitionException {
		ExprContext _localctx = new ExprContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_expr);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(18); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(16);
					((ExprContext)_localctx).VAL = match(VAL);

					         if(!error)
					         {
					            vals.push((((ExprContext)_localctx).VAL!=null?((ExprContext)_localctx).VAL.getText():null));
					         }
					      
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(20); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
			setState(26);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==OPP) {
				{
				{
				setState(22);
				((ExprContext)_localctx).OPP = match(OPP);

				         if(!error)
				         {
				            if(vals.empty())
				            {
				               System.out.print("Opp '"+(((ExprContext)_localctx).OPP!=null?((ExprContext)_localctx).OPP.getText():null)+"' does not have enough values ");
				               error=true;
				            }
				            else
				            {
				               String val1=vals.pop();
				               String s=(((ExprContext)_localctx).OPP!=null?((ExprContext)_localctx).OPP.getText():null);
				               
				               if(s.equals("+"))
				               {
				                  if(vals.empty())
				                  {
				                     System.out.print("Opp '+' does not have enough values ");
				                     error=true;
				                  }
				                  else
				                  {
				                     String val2=vals.pop();
				                     if(val1.equals("true")|val1.equals("false")|val2.equals("true")|val2.equals("false"))
				                     {
				                        System.out.print(" Cannot add boolean variables.");
				                        error=true;
				                     }
				                     else
				                     {
				                        int i1=Integer.parseInt(val1);
				                        int i2=Integer.parseInt(val2);
				                        vals.push(Integer.toString(i2+i1));
				                     }
				                  }
				               }
				               else if(s.equals("-"))
				               {
				                  if(vals.empty())
				                  {
				                     System.out.print("Opp '-' does not have enough values ");
				                     error=true;
				                  }
				                  else
				                  {
				                     String val2=vals.pop();
				                     if(val1.equals("true")|val1.equals("false")|val2.equals("true")|val2.equals("false"))
				                     {
				                        System.out.println("Cannot subtract boolean variables. ");
				                        error=true;
				                     }
				                     else
				                     {
				                        int i1=Integer.parseInt(val1);
				                        int i2=Integer.parseInt(val2);
				                        vals.push(Integer.toString(i2-i1));
				                     }
				                  }
				               }
				               else if(s.equals("*"))
				               {
				                  if(vals.empty())
				                  {
				                     System.out.print("Opp '*' does not have enough values ");
				                     error=true;
				                  }
				                  else
				                  {
				                     String val2=vals.pop();
				                     if(val1.equals("true")|val1.equals("false")|val2.equals("true")|val2.equals("false"))
				                     {
				                        System.out.println("Cannot multiply boolean variables. ");
				                        error=true;
				                     }
				                     else
				                     {
				                        int i1=Integer.parseInt(val1);
				                        int i2=Integer.parseInt(val2);
				                        vals.push(Integer.toString(i2*i1));
				                     }
				                  }
				               }
				               else if(s.equals("/"))
				               {
				                  if(vals.empty())
				                  {
				                     System.out.print("Opp '\' does not have enough values ");
				                     error=true;
				                  }
				                  else
				                  {
				                     String val2=vals.pop();
				                     if(val1.equals("true")|val1.equals("false")|val2.equals("true")|val2.equals("false"))
				                     {
				                        System.out.print("Cannot divide boolean variables. ");
				                        error=true;
				                     }
				                     else
				                     {
				                        int i1=Integer.parseInt(val1);
				                        int i2=Integer.parseInt(val2);
				                        vals.push(Integer.toString(i2/i1));
				                     }
				                  }
				               }
				               else if(s.equals("%"))
				               {
				                  if(vals.empty())
				                  {
				                     System.out.print("Opp '%' does not have enough values ");
				                     error=true;
				                  }
				                  else
				                  {
				                     String val2=vals.pop();
				                     if(val1.equals("true")|val1.equals("false")|val2.equals("true")|val2.equals("false"))
				                     {
				                        System.out.print("Cannot mod boolean variables. ");
				                        error=true;
				                     }
				                     else
				                     {
				                        int i1=Integer.parseInt(val1);
				                        int i2=Integer.parseInt(val2);
				                        vals.push(Integer.toString(i2%i1));
				                     }
				                  }
				               }
				               else if(s.equals("<"))
				               {
				                  if(vals.empty())
				                  {
				                     System.out.print("Opp '<' does not have enough values ");
				                     error=true;
				                  }
				                  else
				                  {
				                     String val2=vals.pop();
				                     if(val1.equals("true")|val1.equals("false")|val2.equals("true")|val2.equals("false"))
				                     {
				                        System.out.print("Cannot compare boolean variables. ");
				                        error=true;
				                     }
				                     else
				                     {
				                        int i1=Integer.parseInt(val1);
				                        int i2=Integer.parseInt(val2);
				                        Boolean b=(i2<i1);
				                        vals.push(String.valueOf(b));
				                     }
				                  }
				               }
				               else if(s.equals("<="))
				               {
				                  if(vals.empty())
				                  {
				                     System.out.print("Opp '<=' does not have enough values ");
				                     error=true;
				                  }
				                  else
				                  {
				                     String val2=vals.pop();
				                     if(val1.equals("true")|val1.equals("false")|val2.equals("true")|val2.equals("false"))
				                     {
				                        System.out.print("Cannot compare boolean variables. ");
				                        error=true;
				                     }
				                     else
				                     {
				                        int i1=Integer.parseInt(val1);
				                        int i2=Integer.parseInt(val2);
				                        Boolean b=(i2<=i1);
				                        vals.push(String.valueOf(b));
				                     }
				                  }
				               }
				               else if(s.equals(">"))
				               {
				                  if(vals.empty())
				                  {
				                     System.out.print("Opp '>' does not have enough values ");
				                     error=true;
				                  }
				                  else
				                  {
				                     String val2=vals.pop();
				                     if(val1.equals("true")|val1.equals("false")|val2.equals("true")|val2.equals("false"))
				                     {
				                        System.out.print("Cannot compare boolean variables. ");
				                        error=true;
				                     }
				                     else
				                     {
				                        int i1=Integer.parseInt(val1);
				                        int i2=Integer.parseInt(val2);
				                        Boolean b=(i2>i1);
				                        vals.push(String.valueOf(b));
				                     }
				                  }
				               }
				               else if(s.equals(">="))
				               {
				                  if(vals.empty())
				                  {
				                     System.out.print("Opp '>=' does not have enough values ");
				                     error=true;
				                  }
				                  else
				                  {
				                     String val2=vals.pop();
				                     if(val1.equals("true")|val1.equals("false")|val2.equals("true")|val2.equals("false"))
				                     {
				                        System.out.print("Cannot compare boolean variables. ");
				                        error=true;
				                     }
				                     else
				                     {
				                        int i1=Integer.parseInt(val1);
				                        int i2=Integer.parseInt(val2);
				                        Boolean b=(i2>=i1);
				                        vals.push(String.valueOf(b));
				                     }
				                  }
				               }
				               else if(s.equals("=="))
				               {
				                  if(vals.empty())
				                  {
				                     System.out.print("Opp '==' does not have enough values ");
				                     error=true;
				                  }
				                  else
				                  {
				                     String val2=vals.pop();
				                     Boolean b=(val2.equals(val1));
				                     vals.push(String.valueOf(b));
				                  }
				               }
				               else if(s.equals("!="))
				               {
				                  if(vals.empty())
				                  {
				                     System.out.print("Opp '!=' does not have enough values ");
				                     error=true;
				                  }
				                  else
				                  {
				                     String val2=vals.pop();
				                     Boolean b=(!(val2.equals(val1)));
				                     vals.push(String.valueOf(b));
				                  }
				               }
				               else if(s.equals("!"))
				               {
				                  if(val1.equals("true"))
				                  {
				                     vals.push("false");
				                  }
				                  else if(val1.equals("false"))
				                  {
				                     vals.push("true");
				                  }
				                  else
				                  {
				                     System.out.print("Cannot 'not' non-booleans ");
				                     error=true;
				                  }
				               }
				               else if(s.equals("&&"))
				               {
				                  if(vals.empty())
				                  {
				                     System.out.print("Opp '&&' does not have enough values ");
				                     error=true;
				                  }
				                  else
				                  {
				                     String val2=vals.pop();
				                     if((val1.equals("true") || val1.equals("false")) && (val2.equals("true") || val2.equals("false")))
				                     {
				                        Boolean b=val2.equals(val1);
				                        vals.push(String.valueOf(b));
				                     }
				                     else
				                     {
				                        System.out.print("Cannot compare non-boolean variables ");
				                        error=true;
				                     }
				                  }
				               }
				               else if(s.equals("||"))
				               {
				                  if(vals.empty())
				                  {
				                     System.out.print("Opp '||' does not have enough values ");
				                     error=true;
				                  }
				                  else
				                  {
				                     String val2=vals.pop();
				                     if((val1.equals("true") || val1.equals("false")) && (val2.equals("true") || val2.equals("false")))
				                     {
				                        Boolean b1=Boolean.parseBoolean(val1);
				                        Boolean b2=Boolean.parseBoolean(val2);
				                        Boolean b=(b1||b2);
				                        vals.push(String.valueOf(b));
				                     }
				                     else
				                     {
				                        System.out.print("Cannot compare non-boolean variables ");
				                        error=true;
				                     }
				                  }
				               }
				               
				               
				            }
				         }
				      
				}
				}
				setState(28);
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

	public static final String _serializedATN =
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\3\6 \4\2\t\2\4\3\t"+
		"\3\3\2\7\2\b\n\2\f\2\16\2\13\13\2\3\2\3\2\6\2\17\n\2\r\2\16\2\20\3\3\3"+
		"\3\6\3\25\n\3\r\3\16\3\26\3\3\3\3\7\3\33\n\3\f\3\16\3\36\13\3\3\3\2\2"+
		"\4\2\4\2\2!\2\16\3\2\2\2\4\24\3\2\2\2\6\b\5\4\3\2\7\6\3\2\2\2\b\13\3\2"+
		"\2\2\t\7\3\2\2\2\t\n\3\2\2\2\n\f\3\2\2\2\13\t\3\2\2\2\f\r\7\5\2\2\r\17"+
		"\b\2\1\2\16\t\3\2\2\2\17\20\3\2\2\2\20\16\3\2\2\2\20\21\3\2\2\2\21\3\3"+
		"\2\2\2\22\23\7\3\2\2\23\25\b\3\1\2\24\22\3\2\2\2\25\26\3\2\2\2\26\24\3"+
		"\2\2\2\26\27\3\2\2\2\27\34\3\2\2\2\30\31\7\4\2\2\31\33\b\3\1\2\32\30\3"+
		"\2\2\2\33\36\3\2\2\2\34\32\3\2\2\2\34\35\3\2\2\2\35\5\3\2\2\2\36\34\3"+
		"\2\2\2\6\t\20\26\34";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}