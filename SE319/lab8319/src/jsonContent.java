// Generated from jsonContent.g4 by ANTLR 4.5.3
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class jsonContent extends Lexer {
	static { RuntimeMetaData.checkVersion("4.5.3", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		EMAIL=1, WS=2, BRACKET=3, EERROR=4, DATE=5, DERROR=6, PHONE=7, PERROR=8, 
		CREDIT=9, CERROR=10, ADDRESS=11, AERROR=12, OTHER=13, OERROR=14;
	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"LOCAL", "DOMAIN", "END", "EMAIL", "WS", "BRACKET", "EERROR", "DAY", "MONTH", 
		"YEAR", "DATE", "DERROR", "THREEDIGIT", "FOURDIGIT", "PHONE", "PERROR", 
		"TWODIGIT", "VISA", "MASTER", "AMERICAN", "DINERS", "JOINTVENTURE", "DISCOVER", 
		"JCB", "CREDIT", "CERROR", "FIVEDIGIT", "ADDRESS", "AERROR", "OTHERELEMENTNAME", 
		"OTHERELEMENTRULES", "OTHER", "OERROR"
	};

	private static final String[] _LITERAL_NAMES = {
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "EMAIL", "WS", "BRACKET", "EERROR", "DATE", "DERROR", "PHONE", "PERROR", 
		"CREDIT", "CERROR", "ADDRESS", "AERROR", "OTHER", "OERROR"
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


	public jsonContent(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "jsonContent.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	@Override
	public void action(RuleContext _localctx, int ruleIndex, int actionIndex) {
		switch (ruleIndex) {
		case 3:
			EMAIL_action((RuleContext)_localctx, actionIndex);
			break;
		case 4:
			WS_action((RuleContext)_localctx, actionIndex);
			break;
		case 5:
			BRACKET_action((RuleContext)_localctx, actionIndex);
			break;
		case 6:
			EERROR_action((RuleContext)_localctx, actionIndex);
			break;
		case 10:
			DATE_action((RuleContext)_localctx, actionIndex);
			break;
		case 11:
			DERROR_action((RuleContext)_localctx, actionIndex);
			break;
		case 14:
			PHONE_action((RuleContext)_localctx, actionIndex);
			break;
		case 15:
			PERROR_action((RuleContext)_localctx, actionIndex);
			break;
		case 24:
			CREDIT_action((RuleContext)_localctx, actionIndex);
			break;
		case 25:
			CERROR_action((RuleContext)_localctx, actionIndex);
			break;
		case 27:
			ADDRESS_action((RuleContext)_localctx, actionIndex);
			break;
		case 28:
			AERROR_action((RuleContext)_localctx, actionIndex);
			break;
		case 31:
			OTHER_action((RuleContext)_localctx, actionIndex);
			break;
		case 32:
			OERROR_action((RuleContext)_localctx, actionIndex);
			break;
		}
	}
	private void EMAIL_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 0:

			                 int start = getText().indexOf('"', 7) + 1;
			                 int end = getText().indexOf('"', start);
			                 System.out.println("Found Email: " + getText().substring(start, end));
			             
			break;
		}
	}
	private void WS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 1:
			skip();
			break;
		}
	}
	private void BRACKET_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 2:
			skip();
			break;
		}
	}
	private void EERROR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 3:

			    System.out.println("Email error: " + getText());

			break;
		}
	}
	private void DATE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 4:

			    int start = getText().indexOf('"', 7) + 1;
			    int end = getText().indexOf('"', start);

			    System.out.println("Found Date: " + getText().substring(start, end));

			break;
		}
	}
	private void DERROR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 5:

			    System.out.println("Date error: " + getText());

			break;
		}
	}
	private void PHONE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 6:

			    int start = getText().indexOf('"', 8) + 1;
			    int end = getText().indexOf('"', start);
			    System.out.println("Found phone: " + getText().substring(start, end));

			break;
		}
	}
	private void PERROR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 7:

			    System.out.println("Phone error: " + getText());

			break;
		}
	}
	private void CREDIT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 8:

			    int start = getText().indexOf('"', 13) + 1;
			    int end = getText().indexOf('"', start);
			    System.out.println("Found card: " + getText().substring(start, end));

			break;
		}
	}
	private void CERROR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 9:

			    System.out.println("Credit error: " + getText());

			break;
		}
	}
	private void ADDRESS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 10:

			    int start = getText().indexOf('"', 9) + 1;
			    int end = getText().indexOf('"', start);
			    System.out.println("Found address: " + getText().substring(start, end));

			break;
		}
	}
	private void AERROR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 11:

			    System.out.println("Address error: " + getText());

			break;
		}
	}
	private void OTHER_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 12:

			    int start = getText().indexOf('"') + 1;
			    int end = getText().indexOf('"', start);
			    String name = getText().substring(start, end);

			    int colon = getText().indexOf(':');
			    int textStart = getText().indexOf('"', colon) + 1;
			    int textEnd = getText().indexOf('"', textStart);
			    String text = getText().substring(textStart, textEnd);

			       if( name.length() >= 3){
			         String xml = name.substring(0,3);
			            if(Character.toLowerCase(xml.charAt(0)) == 'x' || Character.toLowerCase(xml.charAt(1)) == 'm' || Character.toLowerCase(xml.charAt(2)) == 'l'){
			                System.out.println("Can't start an element with XML: " + getText());
			            }else{
			                       System.out.println("Found " +  name  + " : " + text);
			            }
			       }else{
			             System.out.println("Found " +  name  + " : " + text);
			       }



			break;
		}
	}
	private void OERROR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 13:


			    System.out.println("Error with : " + getText());

			break;
		}
	}

	public static final String _serializedATN =
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\2\20\u030e\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31"+
		"\t\31\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t"+
		" \4!\t!\4\"\t\"\3\2\6\2G\n\2\r\2\16\2H\3\2\5\2L\n\2\3\3\6\3O\n\3\r\3\16"+
		"\3P\3\3\5\3T\n\3\3\4\6\4W\n\4\r\4\16\4X\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3"+
		"\5\3\5\3\5\7\5e\n\5\f\5\16\5h\13\5\3\5\3\5\7\5l\n\5\f\5\16\5o\13\5\3\5"+
		"\6\5r\n\5\r\5\16\5s\3\5\3\5\3\5\3\5\7\5z\n\5\f\5\16\5}\13\5\3\5\3\5\5"+
		"\5\u0081\n\5\3\5\3\5\3\6\6\6\u0086\n\6\r\6\16\6\u0087\3\6\3\6\3\7\3\7"+
		"\3\7\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\7\b\u0099\n\b\f\b\16\b\u009c"+
		"\13\b\3\b\3\b\7\b\u00a0\n\b\f\b\16\b\u00a3\13\b\3\b\3\b\5\b\u00a7\n\b"+
		"\3\b\3\b\3\t\7\t\u00ac\n\t\f\t\16\t\u00af\13\t\3\t\3\t\3\t\3\t\3\t\3\t"+
		"\3\t\5\t\u00b8\n\t\3\n\7\n\u00bb\n\n\f\n\16\n\u00be\13\n\3\n\3\n\3\n\5"+
		"\n\u00c3\n\n\3\13\3\13\3\13\3\13\3\13\6\13\u00ca\n\13\r\13\16\13\u00cb"+
		"\3\13\3\13\3\13\3\13\5\13\u00d2\n\13\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3"+
		"\f\7\f\u00dd\n\f\f\f\16\f\u00e0\13\f\3\f\3\f\7\f\u00e4\n\f\f\f\16\f\u00e7"+
		"\13\f\3\f\3\f\7\f\u00eb\n\f\f\f\16\f\u00ee\13\f\3\f\3\f\7\f\u00f2\n\f"+
		"\f\f\16\f\u00f5\13\f\3\f\3\f\7\f\u00f9\n\f\f\f\16\f\u00fc\13\f\3\f\3\f"+
		"\5\f\u0100\n\f\3\f\3\f\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\7\r\u010d\n"+
		"\r\f\r\16\r\u0110\13\r\3\r\3\r\7\r\u0114\n\r\f\r\16\r\u0117\13\r\3\r\3"+
		"\r\5\r\u011b\n\r\3\r\3\r\3\16\5\16\u0120\n\16\3\16\3\16\5\16\u0124\n\16"+
		"\3\16\3\16\5\16\u0128\n\16\3\16\3\16\5\16\u012c\n\16\3\17\5\17\u012f\n"+
		"\17\3\17\3\17\5\17\u0133\n\17\3\17\3\17\5\17\u0137\n\17\3\17\3\17\5\17"+
		"\u013b\n\17\3\17\3\17\5\17\u013f\n\17\3\20\3\20\3\20\3\20\3\20\3\20\3"+
		"\20\3\20\3\20\3\20\7\20\u014b\n\20\f\20\16\20\u014e\13\20\3\20\3\20\7"+
		"\20\u0152\n\20\f\20\16\20\u0155\13\20\3\20\5\20\u0158\n\20\3\20\3\20\5"+
		"\20\u015c\n\20\3\20\3\20\3\20\7\20\u0161\n\20\f\20\16\20\u0164\13\20\3"+
		"\20\3\20\5\20\u0168\n\20\3\20\3\20\3\21\3\21\3\21\3\21\3\21\3\21\3\21"+
		"\3\21\3\21\3\21\7\21\u0176\n\21\f\21\16\21\u0179\13\21\3\21\3\21\7\21"+
		"\u017d\n\21\f\21\16\21\u0180\13\21\3\21\3\21\5\21\u0184\n\21\3\21\3\21"+
		"\3\22\7\22\u0189\n\22\f\22\16\22\u018c\13\22\3\22\3\22\7\22\u0190\n\22"+
		"\f\22\16\22\u0193\13\22\3\22\3\22\7\22\u0197\n\22\f\22\16\22\u019a\13"+
		"\22\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\5\23\u01a8"+
		"\n\23\5\23\u01aa\n\23\3\24\3\24\5\24\u01ae\n\24\3\24\3\24\3\24\3\24\3"+
		"\24\3\24\3\25\3\25\5\25\u01b8\n\25\3\25\3\25\3\25\3\25\3\25\3\25\3\26"+
		"\3\26\3\26\3\26\5\26\u01c4\n\26\3\26\3\26\7\26\u01c8\n\26\f\26\16\26\u01cb"+
		"\13\26\3\26\3\26\3\26\3\26\3\26\3\26\3\26\3\26\3\26\3\26\3\26\3\26\5\26"+
		"\u01d9\n\26\3\27\3\27\3\27\3\27\3\27\3\27\3\30\3\30\3\30\3\30\3\30\3\30"+
		"\3\30\3\30\3\30\3\30\3\30\3\30\3\30\3\30\3\30\3\30\3\30\5\30\u01f2\n\30"+
		"\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31"+
		"\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31\5\31\u020e"+
		"\n\31\3\32\3\32\3\32\3\32\3\32\3\32\3\32\3\32\3\32\3\32\3\32\3\32\3\32"+
		"\3\32\3\32\7\32\u021f\n\32\f\32\16\32\u0222\13\32\3\32\3\32\7\32\u0226"+
		"\n\32\f\32\16\32\u0229\13\32\3\32\3\32\3\32\3\32\3\32\3\32\3\32\5\32\u0232"+
		"\n\32\3\32\7\32\u0235\n\32\f\32\16\32\u0238\13\32\3\32\3\32\5\32\u023c"+
		"\n\32\3\32\3\32\3\33\3\33\3\33\3\33\3\33\3\33\3\33\3\33\3\33\3\33\3\33"+
		"\3\33\3\33\3\33\3\33\7\33\u024f\n\33\f\33\16\33\u0252\13\33\3\33\3\33"+
		"\7\33\u0256\n\33\f\33\16\33\u0259\13\33\3\33\3\33\5\33\u025d\n\33\3\33"+
		"\3\33\3\34\3\34\3\34\3\34\3\34\3\34\3\35\3\35\3\35\3\35\3\35\3\35\3\35"+
		"\3\35\3\35\3\35\3\35\3\35\7\35\u0273\n\35\f\35\16\35\u0276\13\35\3\35"+
		"\3\35\7\35\u027a\n\35\f\35\16\35\u027d\13\35\3\35\6\35\u0280\n\35\r\35"+
		"\16\35\u0281\3\35\7\35\u0285\n\35\f\35\16\35\u0288\13\35\3\35\7\35\u028b"+
		"\n\35\f\35\16\35\u028e\13\35\3\35\5\35\u0291\n\35\3\35\6\35\u0294\n\35"+
		"\r\35\16\35\u0295\3\35\3\35\7\35\u029a\n\35\f\35\16\35\u029d\13\35\3\35"+
		"\3\35\3\35\7\35\u02a2\n\35\f\35\16\35\u02a5\13\35\3\35\3\35\7\35\u02a9"+
		"\n\35\f\35\16\35\u02ac\13\35\3\35\3\35\5\35\u02b0\n\35\3\35\3\35\3\36"+
		"\3\36\3\36\3\36\3\36\3\36\3\36\3\36\3\36\3\36\3\36\3\36\7\36\u02c0\n\36"+
		"\f\36\16\36\u02c3\13\36\3\36\3\36\7\36\u02c7\n\36\f\36\16\36\u02ca\13"+
		"\36\3\36\3\36\5\36\u02ce\n\36\3\36\3\36\3\37\3\37\7\37\u02d4\n\37\f\37"+
		"\16\37\u02d7\13\37\3\37\3\37\3\37\3\37\7\37\u02dd\n\37\f\37\16\37\u02e0"+
		"\13\37\3 \3 \7 \u02e4\n \f \16 \u02e7\13 \3 \3 \3!\3!\3!\5!\u02ee\n!\3"+
		"!\3!\3\"\3\"\7\"\u02f4\n\"\f\"\16\"\u02f7\13\"\3\"\3\"\3\"\3\"\7\"\u02fd"+
		"\n\"\f\"\16\"\u0300\13\"\3\"\3\"\7\"\u0304\n\"\f\"\16\"\u0307\13\"\3\""+
		"\3\"\5\"\u030b\n\"\3\"\3\"\t\u00a1\u0115\u017e\u0257\u02c8\u02f5\u0305"+
		"\2#\3\2\5\2\7\2\t\3\13\4\r\5\17\6\21\2\23\2\25\2\27\7\31\b\33\2\35\2\37"+
		"\t!\n#\2%\2\'\2)\2+\2-\2/\2\61\2\63\13\65\f\67\29\r;\16=\2?\2A\17C\20"+
		"\3\2\32\13\2##&&(/\62=??C\\aac|\u0080\u0080\6\2//\62;C\\c|\3\2\"\"\3\2"+
		"..\5\2\13\f\17\17\"\"\3\2}\177\3\2\62\62\3\2\63;\3\2\63\64\3\2\62;\3\2"+
		"\63\63\3\2\62\64\3\2/\61\4\2\"\"/\60\3\2\63\67\4\2\66\6699\3\2\62\67\3"+
		"\2/\60\4\288::\b\2\"\"))//C\\aac|\5\2\"\"C\\c|\3\2C\\\7\2/\60\62;C\\a"+
		"ac|\13\2\"#&&(/\62=??C\\aac|\u0080\u0080\u035b\2\t\3\2\2\2\2\13\3\2\2"+
		"\2\2\r\3\2\2\2\2\17\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\37\3\2\2\2\2!"+
		"\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2\2\29\3\2\2\2\2;\3\2\2\2\2A\3\2\2\2\2"+
		"C\3\2\2\2\3F\3\2\2\2\5N\3\2\2\2\7V\3\2\2\2\tZ\3\2\2\2\13\u0085\3\2\2\2"+
		"\r\u008b\3\2\2\2\17\u008e\3\2\2\2\21\u00b7\3\2\2\2\23\u00c2\3\2\2\2\25"+
		"\u00d1\3\2\2\2\27\u00d3\3\2\2\2\31\u0103\3\2\2\2\33\u011f\3\2\2\2\35\u012e"+
		"\3\2\2\2\37\u0140\3\2\2\2!\u016b\3\2\2\2#\u018a\3\2\2\2%\u01a9\3\2\2\2"+
		"\'\u01ab\3\2\2\2)\u01b5\3\2\2\2+\u01d8\3\2\2\2-\u01da\3\2\2\2/\u01f1\3"+
		"\2\2\2\61\u020d\3\2\2\2\63\u020f\3\2\2\2\65\u023f\3\2\2\2\67\u0260\3\2"+
		"\2\29\u0266\3\2\2\2;\u02b3\3\2\2\2=\u02d1\3\2\2\2?\u02e1\3\2\2\2A\u02ea"+
		"\3\2\2\2C\u02f1\3\2\2\2EG\t\2\2\2FE\3\2\2\2GH\3\2\2\2HF\3\2\2\2HI\3\2"+
		"\2\2IK\3\2\2\2JL\7\60\2\2KJ\3\2\2\2KL\3\2\2\2L\4\3\2\2\2MO\t\3\2\2NM\3"+
		"\2\2\2OP\3\2\2\2PN\3\2\2\2PQ\3\2\2\2QS\3\2\2\2RT\7\60\2\2SR\3\2\2\2ST"+
		"\3\2\2\2T\6\3\2\2\2UW\t\3\2\2VU\3\2\2\2WX\3\2\2\2XV\3\2\2\2XY\3\2\2\2"+
		"Y\b\3\2\2\2Z[\7$\2\2[\\\7G\2\2\\]\7O\2\2]^\7C\2\2^_\7K\2\2_`\7N\2\2`a"+
		"\7$\2\2ab\7<\2\2bf\3\2\2\2ce\t\4\2\2dc\3\2\2\2eh\3\2\2\2fd\3\2\2\2fg\3"+
		"\2\2\2gi\3\2\2\2hf\3\2\2\2im\7$\2\2jl\t\4\2\2kj\3\2\2\2lo\3\2\2\2mk\3"+
		"\2\2\2mn\3\2\2\2nq\3\2\2\2om\3\2\2\2pr\5\3\2\2qp\3\2\2\2rs\3\2\2\2sq\3"+
		"\2\2\2st\3\2\2\2tu\3\2\2\2uv\7B\2\2vw\5\5\3\2w{\5\7\4\2xz\t\4\2\2yx\3"+
		"\2\2\2z}\3\2\2\2{y\3\2\2\2{|\3\2\2\2|~\3\2\2\2}{\3\2\2\2~\u0080\7$\2\2"+
		"\177\u0081\t\5\2\2\u0080\177\3\2\2\2\u0080\u0081\3\2\2\2\u0081\u0082\3"+
		"\2\2\2\u0082\u0083\b\5\2\2\u0083\n\3\2\2\2\u0084\u0086\t\6\2\2\u0085\u0084"+
		"\3\2\2\2\u0086\u0087\3\2\2\2\u0087\u0085\3\2\2\2\u0087\u0088\3\2\2\2\u0088"+
		"\u0089\3\2\2\2\u0089\u008a\b\6\3\2\u008a\f\3\2\2\2\u008b\u008c\t\7\2\2"+
		"\u008c\u008d\b\7\4\2\u008d\16\3\2\2\2\u008e\u008f\7$\2\2\u008f\u0090\7"+
		"G\2\2\u0090\u0091\7O\2\2\u0091\u0092\7C\2\2\u0092\u0093\7K\2\2\u0093\u0094"+
		"\7N\2\2\u0094\u0095\7$\2\2\u0095\u0096\7<\2\2\u0096\u009a\3\2\2\2\u0097"+
		"\u0099\t\4\2\2\u0098\u0097\3\2\2\2\u0099\u009c\3\2\2\2\u009a\u0098\3\2"+
		"\2\2\u009a\u009b\3\2\2\2\u009b\u009d\3\2\2\2\u009c\u009a\3\2\2\2\u009d"+
		"\u00a1\7$\2\2\u009e\u00a0\13\2\2\2\u009f\u009e\3\2\2\2\u00a0\u00a3\3\2"+
		"\2\2\u00a1\u00a2\3\2\2\2\u00a1\u009f\3\2\2\2\u00a2\u00a4\3\2\2\2\u00a3"+
		"\u00a1\3\2\2\2\u00a4\u00a6\7$\2\2\u00a5\u00a7\t\5\2\2\u00a6\u00a5\3\2"+
		"\2\2\u00a6\u00a7\3\2\2\2\u00a7\u00a8\3\2\2\2\u00a8\u00a9\b\b\5\2\u00a9"+
		"\20\3\2\2\2\u00aa\u00ac\t\b\2\2\u00ab\u00aa\3\2\2\2\u00ac\u00af\3\2\2"+
		"\2\u00ad\u00ab\3\2\2\2\u00ad\u00ae\3\2\2\2\u00ae\u00b0\3\2\2\2\u00af\u00ad"+
		"\3\2\2\2\u00b0\u00b8\t\t\2\2\u00b1\u00b2\t\n\2\2\u00b2\u00b8\t\13\2\2"+
		"\u00b3\u00b4\7\65\2\2\u00b4\u00b8\7\62\2\2\u00b5\u00b6\7\65\2\2\u00b6"+
		"\u00b8\7\63\2\2\u00b7\u00ad\3\2\2\2\u00b7\u00b1\3\2\2\2\u00b7\u00b3\3"+
		"\2\2\2\u00b7\u00b5\3\2\2\2\u00b8\22\3\2\2\2\u00b9\u00bb\t\b\2\2\u00ba"+
		"\u00b9\3\2\2\2\u00bb\u00be\3\2\2\2\u00bc\u00ba\3\2\2\2\u00bc\u00bd\3\2"+
		"\2\2\u00bd\u00bf\3\2\2\2\u00be\u00bc\3\2\2\2\u00bf\u00c3\t\t\2\2\u00c0"+
		"\u00c1\t\f\2\2\u00c1\u00c3\t\r\2\2\u00c2\u00bc\3\2\2\2\u00c2\u00c0\3\2"+
		"\2\2\u00c3\24\3\2\2\2\u00c4\u00c5\7\64\2\2\u00c5\u00c6\7\62\2\2\u00c6"+
		"\u00c7\3\2\2\2\u00c7\u00c8\t\13\2\2\u00c8\u00ca\t\13\2\2\u00c9\u00c4\3"+
		"\2\2\2\u00ca\u00cb\3\2\2\2\u00cb\u00c9\3\2\2\2\u00cb\u00cc\3\2\2\2\u00cc"+
		"\u00d2\3\2\2\2\u00cd\u00ce\7\64\2\2\u00ce\u00cf\7\63\2\2\u00cf\u00d0\7"+
		"\62\2\2\u00d0\u00d2\7\62\2\2\u00d1\u00c9\3\2\2\2\u00d1\u00cd\3\2\2\2\u00d2"+
		"\26\3\2\2\2\u00d3\u00d4\7$\2\2\u00d4\u00d5\7F\2\2\u00d5\u00d6\7C\2\2\u00d6"+
		"\u00d7\7V\2\2\u00d7\u00d8\7G\2\2\u00d8\u00d9\7$\2\2\u00d9\u00da\7<\2\2"+
		"\u00da\u00de\3\2\2\2\u00db\u00dd\t\4\2\2\u00dc\u00db\3\2\2\2\u00dd\u00e0"+
		"\3\2\2\2\u00de\u00dc\3\2\2\2\u00de\u00df\3\2\2\2\u00df\u00e1\3\2\2\2\u00e0"+
		"\u00de\3\2\2\2\u00e1\u00e5\7$\2\2\u00e2\u00e4\t\4\2\2\u00e3\u00e2\3\2"+
		"\2\2\u00e4\u00e7\3\2\2\2\u00e5\u00e3\3\2\2\2\u00e5\u00e6\3\2\2\2\u00e6"+
		"\u00e8\3\2\2\2\u00e7\u00e5\3\2\2\2\u00e8\u00ec\5\21\t\2\u00e9\u00eb\t"+
		"\16\2\2\u00ea\u00e9\3\2\2\2\u00eb\u00ee\3\2\2\2\u00ec\u00ea\3\2\2\2\u00ec"+
		"\u00ed\3\2\2\2\u00ed\u00ef\3\2\2\2\u00ee\u00ec\3\2\2\2\u00ef\u00f3\5\23"+
		"\n\2\u00f0\u00f2\t\16\2\2\u00f1\u00f0\3\2\2\2\u00f2\u00f5\3\2\2\2\u00f3"+
		"\u00f1\3\2\2\2\u00f3\u00f4\3\2\2\2\u00f4\u00f6\3\2\2\2\u00f5\u00f3\3\2"+
		"\2\2\u00f6\u00fa\5\25\13\2\u00f7\u00f9\t\4\2\2\u00f8\u00f7\3\2\2\2\u00f9"+
		"\u00fc\3\2\2\2\u00fa\u00f8\3\2\2\2\u00fa\u00fb\3\2\2\2\u00fb\u00fd\3\2"+
		"\2\2\u00fc\u00fa\3\2\2\2\u00fd\u00ff\7$\2\2\u00fe\u0100\t\5\2\2\u00ff"+
		"\u00fe\3\2\2\2\u00ff\u0100\3\2\2\2\u0100\u0101\3\2\2\2\u0101\u0102\b\f"+
		"\6\2\u0102\30\3\2\2\2\u0103\u0104\7$\2\2\u0104\u0105\7F\2\2\u0105\u0106"+
		"\7C\2\2\u0106\u0107\7V\2\2\u0107\u0108\7G\2\2\u0108\u0109\7$\2\2\u0109"+
		"\u010a\7<\2\2\u010a\u010e\3\2\2\2\u010b\u010d\t\4\2\2\u010c\u010b\3\2"+
		"\2\2\u010d\u0110\3\2\2\2\u010e\u010c\3\2\2\2\u010e\u010f\3\2\2\2\u010f"+
		"\u0111\3\2\2\2\u0110\u010e\3\2\2\2\u0111\u0115\7$\2\2\u0112\u0114\13\2"+
		"\2\2\u0113\u0112\3\2\2\2\u0114\u0117\3\2\2\2\u0115\u0116\3\2\2\2\u0115"+
		"\u0113\3\2\2\2\u0116\u0118\3\2\2\2\u0117\u0115\3\2\2\2\u0118\u011a\7$"+
		"\2\2\u0119\u011b\t\5\2\2\u011a\u0119\3\2\2\2\u011a\u011b\3\2\2\2\u011b"+
		"\u011c\3\2\2\2\u011c\u011d\b\r\7\2\u011d\32\3\2\2\2\u011e\u0120\t\17\2"+
		"\2\u011f\u011e\3\2\2\2\u011f\u0120\3\2\2\2\u0120\u0121\3\2\2\2\u0121\u0123"+
		"\t\13\2\2\u0122\u0124\t\17\2\2\u0123\u0122\3\2\2\2\u0123\u0124\3\2\2\2"+
		"\u0124\u0125\3\2\2\2\u0125\u0127\t\13\2\2\u0126\u0128\t\17\2\2\u0127\u0126"+
		"\3\2\2\2\u0127\u0128\3\2\2\2\u0128\u0129\3\2\2\2\u0129\u012b\t\13\2\2"+
		"\u012a\u012c\t\17\2\2\u012b\u012a\3\2\2\2\u012b\u012c\3\2\2\2\u012c\34"+
		"\3\2\2\2\u012d\u012f\t\17\2\2\u012e\u012d\3\2\2\2\u012e\u012f\3\2\2\2"+
		"\u012f\u0130\3\2\2\2\u0130\u0132\t\13\2\2\u0131\u0133\t\17\2\2\u0132\u0131"+
		"\3\2\2\2\u0132\u0133\3\2\2\2\u0133\u0134\3\2\2\2\u0134\u0136\t\13\2\2"+
		"\u0135\u0137\t\17\2\2\u0136\u0135\3\2\2\2\u0136\u0137\3\2\2\2\u0137\u0138"+
		"\3\2\2\2\u0138\u013a\t\13\2\2\u0139\u013b\t\17\2\2\u013a\u0139\3\2\2\2"+
		"\u013a\u013b\3\2\2\2\u013b\u013c\3\2\2\2\u013c\u013e\t\13\2\2\u013d\u013f"+
		"\t\17\2\2\u013e\u013d\3\2\2\2\u013e\u013f\3\2\2\2\u013f\36\3\2\2\2\u0140"+
		"\u0141\7$\2\2\u0141\u0142\7R\2\2\u0142\u0143\7J\2\2\u0143\u0144\7Q\2\2"+
		"\u0144\u0145\7P\2\2\u0145\u0146\7G\2\2\u0146\u0147\7$\2\2\u0147\u0148"+
		"\7<\2\2\u0148\u014c\3\2\2\2\u0149\u014b\t\4\2\2\u014a\u0149\3\2\2\2\u014b"+
		"\u014e\3\2\2\2\u014c\u014a\3\2\2\2\u014c\u014d\3\2\2\2\u014d\u014f\3\2"+
		"\2\2\u014e\u014c\3\2\2\2\u014f\u0153\7$\2\2\u0150\u0152\t\4\2\2\u0151"+
		"\u0150\3\2\2\2\u0152\u0155\3\2\2\2\u0153\u0151\3\2\2\2\u0153\u0154\3\2"+
		"\2\2\u0154\u0157\3\2\2\2\u0155\u0153\3\2\2\2\u0156\u0158\7*\2\2\u0157"+
		"\u0156\3\2\2\2\u0157\u0158\3\2\2\2\u0158\u0159\3\2\2\2\u0159\u015b\5\33"+
		"\16\2\u015a\u015c\7+\2\2\u015b\u015a\3\2\2\2\u015b\u015c\3\2\2\2\u015c"+
		"\u015d\3\2\2\2\u015d\u015e\5\33\16\2\u015e\u0162\5\35\17\2\u015f\u0161"+
		"\t\4\2\2\u0160\u015f\3\2\2\2\u0161\u0164\3\2\2\2\u0162\u0160\3\2\2\2\u0162"+
		"\u0163\3\2\2\2\u0163\u0165\3\2\2\2\u0164\u0162\3\2\2\2\u0165\u0167\7$"+
		"\2\2\u0166\u0168\t\5\2\2\u0167\u0166\3\2\2\2\u0167\u0168\3\2\2\2\u0168"+
		"\u0169\3\2\2\2\u0169\u016a\b\20\b\2\u016a \3\2\2\2\u016b\u016c\7$\2\2"+
		"\u016c\u016d\7R\2\2\u016d\u016e\7J\2\2\u016e\u016f\7Q\2\2\u016f\u0170"+
		"\7P\2\2\u0170\u0171\7G\2\2\u0171\u0172\7$\2\2\u0172\u0173\7<\2\2\u0173"+
		"\u0177\3\2\2\2\u0174\u0176\t\4\2\2\u0175\u0174\3\2\2\2\u0176\u0179\3\2"+
		"\2\2\u0177\u0175\3\2\2\2\u0177\u0178\3\2\2\2\u0178\u017a\3\2\2\2\u0179"+
		"\u0177\3\2\2\2\u017a\u017e\7$\2\2\u017b\u017d\13\2\2\2\u017c\u017b\3\2"+
		"\2\2\u017d\u0180\3\2\2\2\u017e\u017f\3\2\2\2\u017e\u017c\3\2\2\2\u017f"+
		"\u0181\3\2\2\2\u0180\u017e\3\2\2\2\u0181\u0183\7$\2\2\u0182\u0184\t\5"+
		"\2\2\u0183\u0182\3\2\2\2\u0183\u0184\3\2\2\2\u0184\u0185\3\2\2\2\u0185"+
		"\u0186\b\21\t\2\u0186\"\3\2\2\2\u0187\u0189\t\17\2\2\u0188\u0187\3\2\2"+
		"\2\u0189\u018c\3\2\2\2\u018a\u0188\3\2\2\2\u018a\u018b\3\2\2\2\u018b\u018d"+
		"\3\2\2\2\u018c\u018a\3\2\2\2\u018d\u0191\t\13\2\2\u018e\u0190\t\17\2\2"+
		"\u018f\u018e\3\2\2\2\u0190\u0193\3\2\2\2\u0191\u018f\3\2\2\2\u0191\u0192"+
		"\3\2\2\2\u0192\u0194\3\2\2\2\u0193\u0191\3\2\2\2\u0194\u0198\t\13\2\2"+
		"\u0195\u0197\t\17\2\2\u0196\u0195\3\2\2\2\u0197\u019a\3\2\2\2\u0198\u0196"+
		"\3\2\2\2\u0198\u0199\3\2\2\2\u0199$\3\2\2\2\u019a\u0198\3\2\2\2\u019b"+
		"\u019c\7\66\2\2\u019c\u019d\5\33\16\2\u019d\u019e\5\35\17\2\u019e\u019f"+
		"\5\35\17\2\u019f\u01a0\5\35\17\2\u01a0\u01aa\3\2\2\2\u01a1\u01a2\7\66"+
		"\2\2\u01a2\u01a3\5\33\16\2\u01a3\u01a4\5\35\17\2\u01a4\u01a5\5\35\17\2"+
		"\u01a5\u01a7\t\13\2\2\u01a6\u01a8\t\17\2\2\u01a7\u01a6\3\2\2\2\u01a7\u01a8"+
		"\3\2\2\2\u01a8\u01aa\3\2\2\2\u01a9\u019b\3\2\2\2\u01a9\u01a1\3\2\2\2\u01aa"+
		"&\3\2\2\2\u01ab\u01ad\7\67\2\2\u01ac\u01ae\t\17\2\2\u01ad\u01ac\3\2\2"+
		"\2\u01ad\u01ae\3\2\2\2\u01ae\u01af\3\2\2\2\u01af\u01b0\t\20\2\2\u01b0"+
		"\u01b1\5#\22\2\u01b1\u01b2\5\35\17\2\u01b2\u01b3\5\35\17\2\u01b3\u01b4"+
		"\5\35\17\2\u01b4(\3\2\2\2\u01b5\u01b7\7\65\2\2\u01b6\u01b8\t\17\2\2\u01b7"+
		"\u01b6\3\2\2\2\u01b7\u01b8\3\2\2\2\u01b8\u01b9\3\2\2\2\u01b9\u01ba\t\21"+
		"\2\2\u01ba\u01bb\5#\22\2\u01bb\u01bc\5\35\17\2\u01bc\u01bd\5\35\17\2\u01bd"+
		"\u01be\5\33\16\2\u01be*\3\2\2\2\u01bf\u01c0\7\65\2\2\u01c0\u01c1\7\62"+
		"\2\2\u01c1\u01c3\3\2\2\2\u01c2\u01c4\t\17\2\2\u01c3\u01c2\3\2\2\2\u01c3"+
		"\u01c4\3\2\2\2\u01c4\u01c5\3\2\2\2\u01c5\u01c9\t\22\2\2\u01c6\u01c8\t"+
		"\23\2\2\u01c7\u01c6\3\2\2\2\u01c8\u01cb\3\2\2\2\u01c9\u01c7\3\2\2\2\u01c9"+
		"\u01ca\3\2\2\2\u01ca\u01cc\3\2\2\2\u01cb\u01c9\3\2\2\2\u01cc\u01cd\t\13"+
		"\2\2\u01cd\u01ce\5\35\17\2\u01ce\u01cf\5\35\17\2\u01cf\u01d0\5#\22\2\u01d0"+
		"\u01d9\3\2\2\2\u01d1\u01d2\7\65\2\2\u01d2\u01d3\t\24\2\2\u01d3\u01d4\5"+
		"#\22\2\u01d4\u01d5\5\35\17\2\u01d5\u01d6\5\35\17\2\u01d6\u01d7\5#\22\2"+
		"\u01d7\u01d9\3\2\2\2\u01d8\u01bf\3\2\2\2\u01d8\u01d1\3\2\2\2\u01d9,\3"+
		"\2\2\2\u01da\u01db\7\67\2\2\u01db\u01dc\5\33\16\2\u01dc\u01dd\5\35\17"+
		"\2\u01dd\u01de\5\35\17\2\u01de\u01df\5\35\17\2\u01df.\3\2\2\2\u01e0\u01e1"+
		"\78\2\2\u01e1\u01e2\7\62\2\2\u01e2\u01e3\7\63\2\2\u01e3\u01e4\7\63\2\2"+
		"\u01e4\u01e5\3\2\2\2\u01e5\u01e6\5\35\17\2\u01e6\u01e7\5\35\17\2\u01e7"+
		"\u01e8\5\35\17\2\u01e8\u01f2\3\2\2\2\u01e9\u01ea\78\2\2\u01ea\u01eb\7"+
		"\67\2\2\u01eb\u01ec\3\2\2\2\u01ec\u01ed\5#\22\2\u01ed\u01ee\5\35\17\2"+
		"\u01ee\u01ef\5\35\17\2\u01ef\u01f0\5\35\17\2\u01f0\u01f2\3\2\2\2\u01f1"+
		"\u01e0\3\2\2\2\u01f1\u01e9\3\2\2\2\u01f2\60\3\2\2\2\u01f3\u01f4\7\64\2"+
		"\2\u01f4\u01f5\7\63\2\2\u01f5\u01f6\7\65\2\2\u01f6\u01f7\7\63\2\2\u01f7"+
		"\u01f8\3\2\2\2\u01f8\u01f9\5\35\17\2\u01f9\u01fa\5\35\17\2\u01fa\u01fb"+
		"\5\33\16\2\u01fb\u020e\3\2\2\2\u01fc\u01fd\7\63\2\2\u01fd\u01fe\7:\2\2"+
		"\u01fe\u01ff\7\62\2\2\u01ff\u0200\7\62\2\2\u0200\u0201\3\2\2\2\u0201\u0202"+
		"\5\35\17\2\u0202\u0203\5\35\17\2\u0203\u0204\5\33\16\2\u0204\u020e\3\2"+
		"\2\2\u0205\u0206\7\65\2\2\u0206\u0207\7\67\2\2\u0207\u0208\3\2\2\2\u0208"+
		"\u0209\5#\22\2\u0209\u020a\5\35\17\2\u020a\u020b\5\35\17\2\u020b\u020c"+
		"\5\35\17\2\u020c\u020e\3\2\2\2\u020d\u01f3\3\2\2\2\u020d\u01fc\3\2\2\2"+
		"\u020d\u0205\3\2\2\2\u020e\62\3\2\2\2\u020f\u0210\7$\2\2\u0210\u0211\7"+
		"E\2\2\u0211\u0212\7T\2\2\u0212\u0213\7G\2\2\u0213\u0214\7F\2\2\u0214\u0215"+
		"\7K\2\2\u0215\u0216\7V\2\2\u0216\u0217\7E\2\2\u0217\u0218\7C\2\2\u0218"+
		"\u0219\7T\2\2\u0219\u021a\7F\2\2\u021a\u021b\7$\2\2\u021b\u021c\7<\2\2"+
		"\u021c\u0220\3\2\2\2\u021d\u021f\t\4\2\2\u021e\u021d\3\2\2\2\u021f\u0222"+
		"\3\2\2\2\u0220\u021e\3\2\2\2\u0220\u0221\3\2\2\2\u0221\u0223\3\2\2\2\u0222"+
		"\u0220\3\2\2\2\u0223\u0227\7$\2\2\u0224\u0226\t\4\2\2\u0225\u0224\3\2"+
		"\2\2\u0226\u0229\3\2\2\2\u0227\u0225\3\2\2\2\u0227\u0228\3\2\2\2\u0228"+
		"\u0231\3\2\2\2\u0229\u0227\3\2\2\2\u022a\u0232\5%\23\2\u022b\u0232\5\'"+
		"\24\2\u022c\u0232\5)\25\2\u022d\u0232\5+\26\2\u022e\u0232\5-\27\2\u022f"+
		"\u0232\5/\30\2\u0230\u0232\5\61\31\2\u0231\u022a\3\2\2\2\u0231\u022b\3"+
		"\2\2\2\u0231\u022c\3\2\2\2\u0231\u022d\3\2\2\2\u0231\u022e\3\2\2\2\u0231"+
		"\u022f\3\2\2\2\u0231\u0230\3\2\2\2\u0232\u0236\3\2\2\2\u0233\u0235\t\4"+
		"\2\2\u0234\u0233\3\2\2\2\u0235\u0238\3\2\2\2\u0236\u0234\3\2\2\2\u0236"+
		"\u0237\3\2\2\2\u0237\u0239\3\2\2\2\u0238\u0236\3\2\2\2\u0239\u023b\7$"+
		"\2\2\u023a\u023c\t\5\2\2\u023b\u023a\3\2\2\2\u023b\u023c\3\2\2\2\u023c"+
		"\u023d\3\2\2\2\u023d\u023e\b\32\n\2\u023e\64\3\2\2\2\u023f\u0240\7$\2"+
		"\2\u0240\u0241\7E\2\2\u0241\u0242\7T\2\2\u0242\u0243\7G\2\2\u0243\u0244"+
		"\7F\2\2\u0244\u0245\7K\2\2\u0245\u0246\7V\2\2\u0246\u0247\7E\2\2\u0247"+
		"\u0248\7C\2\2\u0248\u0249\7T\2\2\u0249\u024a\7F\2\2\u024a\u024b\7$\2\2"+
		"\u024b\u024c\7<\2\2\u024c\u0250\3\2\2\2\u024d\u024f\t\4\2\2\u024e\u024d"+
		"\3\2\2\2\u024f\u0252\3\2\2\2\u0250\u024e\3\2\2\2\u0250\u0251\3\2\2\2\u0251"+
		"\u0253\3\2\2\2\u0252\u0250\3\2\2\2\u0253\u0257\7$\2\2\u0254\u0256\13\2"+
		"\2\2\u0255\u0254\3\2\2\2\u0256\u0259\3\2\2\2\u0257\u0258\3\2\2\2\u0257"+
		"\u0255\3\2\2\2\u0258\u025a\3\2\2\2\u0259\u0257\3\2\2\2\u025a\u025c\7$"+
		"\2\2\u025b\u025d\t\5\2\2\u025c\u025b\3\2\2\2\u025c\u025d\3\2\2\2\u025d"+
		"\u025e\3\2\2\2\u025e\u025f\b\33\13\2\u025f\66\3\2\2\2\u0260\u0261\t\13"+
		"\2\2\u0261\u0262\t\13\2\2\u0262\u0263\t\13\2\2\u0263\u0264\t\13\2\2\u0264"+
		"\u0265\t\13\2\2\u02658\3\2\2\2\u0266\u0267\7$\2\2\u0267\u0268\7C\2\2\u0268"+
		"\u0269\7f\2\2\u0269\u026a\7f\2\2\u026a\u026b\7t\2\2\u026b\u026c\7g\2\2"+
		"\u026c\u026d\7u\2\2\u026d\u026e\7u\2\2\u026e\u026f\7$\2\2\u026f\u0270"+
		"\7<\2\2\u0270\u0274\3\2\2\2\u0271\u0273\t\4\2\2\u0272\u0271\3\2\2\2\u0273"+
		"\u0276\3\2\2\2\u0274\u0272\3\2\2\2\u0274\u0275\3\2\2\2\u0275\u0277\3\2"+
		"\2\2\u0276\u0274\3\2\2\2\u0277\u027b\7$\2\2\u0278\u027a\t\4\2\2\u0279"+
		"\u0278\3\2\2\2\u027a\u027d\3\2\2\2\u027b\u0279\3\2\2\2\u027b\u027c\3\2"+
		"\2\2\u027c\u027f\3\2\2\2\u027d\u027b\3\2\2\2\u027e\u0280\t\13\2\2\u027f"+
		"\u027e\3\2\2\2\u0280\u0281\3\2\2\2\u0281\u027f\3\2\2\2\u0281\u0282\3\2"+
		"\2\2\u0282\u0286\3\2\2\2\u0283\u0285\t\4\2\2\u0284\u0283\3\2\2\2\u0285"+
		"\u0288\3\2\2\2\u0286\u0284\3\2\2\2\u0286\u0287\3\2\2\2\u0287\u028c\3\2"+
		"\2\2\u0288\u0286\3\2\2\2\u0289\u028b\t\25\2\2\u028a\u0289\3\2\2\2\u028b"+
		"\u028e\3\2\2\2\u028c\u028a\3\2\2\2\u028c\u028d\3\2\2\2\u028d\u0290\3\2"+
		"\2\2\u028e\u028c\3\2\2\2\u028f\u0291\t\5\2\2\u0290\u028f\3\2\2\2\u0290"+
		"\u0291\3\2\2\2\u0291\u0293\3\2\2\2\u0292\u0294\t\26\2\2\u0293\u0292\3"+
		"\2\2\2\u0294\u0295\3\2\2\2\u0295\u0293\3\2\2\2\u0295\u0296\3\2\2\2\u0296"+
		"\u0297\3\2\2\2\u0297\u029b\t\5\2\2\u0298\u029a\t\4\2\2\u0299\u0298\3\2"+
		"\2\2\u029a\u029d\3\2\2\2\u029b\u0299\3\2\2\2\u029b\u029c\3\2\2\2\u029c"+
		"\u029e\3\2\2\2\u029d\u029b\3\2\2\2\u029e\u029f\t\27\2\2\u029f\u02a3\t"+
		"\27\2\2\u02a0\u02a2\t\4\2\2\u02a1\u02a0\3\2\2\2\u02a2\u02a5\3\2\2\2\u02a3"+
		"\u02a1\3\2\2\2\u02a3\u02a4\3\2\2\2\u02a4\u02a6\3\2\2\2\u02a5\u02a3\3\2"+
		"\2\2\u02a6\u02aa\5\67\34\2\u02a7\u02a9\t\4\2\2\u02a8\u02a7\3\2\2\2\u02a9"+
		"\u02ac\3\2\2\2\u02aa\u02a8\3\2\2\2\u02aa\u02ab\3\2\2\2\u02ab\u02ad\3\2"+
		"\2\2\u02ac\u02aa\3\2\2\2\u02ad\u02af\7$\2\2\u02ae\u02b0\t\5\2\2\u02af"+
		"\u02ae\3\2\2\2\u02af\u02b0\3\2\2\2\u02b0\u02b1\3\2\2\2\u02b1\u02b2\b\35"+
		"\f\2\u02b2:\3\2\2\2\u02b3\u02b4\7$\2\2\u02b4\u02b5\7C\2\2\u02b5\u02b6"+
		"\7f\2\2\u02b6\u02b7\7f\2\2\u02b7\u02b8\7t\2\2\u02b8\u02b9\7g\2\2\u02b9"+
		"\u02ba\7u\2\2\u02ba\u02bb\7u\2\2\u02bb\u02bc\7$\2\2\u02bc\u02bd\7<\2\2"+
		"\u02bd\u02c1\3\2\2\2\u02be\u02c0\t\4\2\2\u02bf\u02be\3\2\2\2\u02c0\u02c3"+
		"\3\2\2\2\u02c1\u02bf\3\2\2\2\u02c1\u02c2\3\2\2\2\u02c2\u02c4\3\2\2\2\u02c3"+
		"\u02c1\3\2\2\2\u02c4\u02c8\7$\2\2\u02c5\u02c7\13\2\2\2\u02c6\u02c5\3\2"+
		"\2\2\u02c7\u02ca\3\2\2\2\u02c8\u02c9\3\2\2\2\u02c8\u02c6\3\2\2\2\u02c9"+
		"\u02cb\3\2\2\2\u02ca\u02c8\3\2\2\2\u02cb\u02cd\7$\2\2\u02cc\u02ce\t\5"+
		"\2\2\u02cd\u02cc\3\2\2\2\u02cd\u02ce\3\2\2\2\u02ce\u02cf\3\2\2\2\u02cf"+
		"\u02d0\b\36\r\2\u02d0<\3\2\2\2\u02d1\u02d5\7$\2\2\u02d2\u02d4\t\30\2\2"+
		"\u02d3\u02d2\3\2\2\2\u02d4\u02d7\3\2\2\2\u02d5\u02d3\3\2\2\2\u02d5\u02d6"+
		"\3\2\2\2\u02d6\u02d8\3\2\2\2\u02d7\u02d5\3\2\2\2\u02d8\u02d9\7$\2\2\u02d9"+
		"\u02da\7<\2\2\u02da\u02de\3\2\2\2\u02db\u02dd\t\4\2\2\u02dc\u02db\3\2"+
		"\2\2\u02dd\u02e0\3\2\2\2\u02de\u02dc\3\2\2\2\u02de\u02df\3\2\2\2\u02df"+
		">\3\2\2\2\u02e0\u02de\3\2\2\2\u02e1\u02e5\7$\2\2\u02e2\u02e4\t\31\2\2"+
		"\u02e3\u02e2\3\2\2\2\u02e4\u02e7\3\2\2\2\u02e5\u02e3\3\2\2\2\u02e5\u02e6"+
		"\3\2\2\2\u02e6\u02e8\3\2\2\2\u02e7\u02e5\3\2\2\2\u02e8\u02e9\7$\2\2\u02e9"+
		"@\3\2\2\2\u02ea\u02eb\5=\37\2\u02eb\u02ed\5? \2\u02ec\u02ee\t\5\2\2\u02ed"+
		"\u02ec\3\2\2\2\u02ed\u02ee\3\2\2\2\u02ee\u02ef\3\2\2\2\u02ef\u02f0\b!"+
		"\16\2\u02f0B\3\2\2\2\u02f1\u02f5\7$\2\2\u02f2\u02f4\13\2\2\2\u02f3\u02f2"+
		"\3\2\2\2\u02f4\u02f7\3\2\2\2\u02f5\u02f6\3\2\2\2\u02f5\u02f3\3\2\2\2\u02f6"+
		"\u02f8\3\2\2\2\u02f7\u02f5\3\2\2\2\u02f8\u02f9\7$\2\2\u02f9\u02fa\7<\2"+
		"\2\u02fa\u02fe\3\2\2\2\u02fb\u02fd\t\4\2\2\u02fc\u02fb\3\2\2\2\u02fd\u0300"+
		"\3\2\2\2\u02fe\u02fc\3\2\2\2\u02fe\u02ff\3\2\2\2\u02ff\u0301\3\2\2\2\u0300"+
		"\u02fe\3\2\2\2\u0301\u0305\7$\2\2\u0302\u0304\13\2\2\2\u0303\u0302\3\2"+
		"\2\2\u0304\u0307\3\2\2\2\u0305\u0306\3\2\2\2\u0305\u0303\3\2\2\2\u0306"+
		"\u0308\3\2\2\2\u0307\u0305\3\2\2\2\u0308\u030a\7$\2\2\u0309\u030b\t\5"+
		"\2\2\u030a\u0309\3\2\2\2\u030a\u030b\3\2\2\2\u030b\u030c\3\2\2\2\u030c"+
		"\u030d\b\"\17\2\u030dD\3\2\2\2\\\2HKPSXfms{\u0080\u0087\u009a\u00a1\u00a6"+
		"\u00ad\u00b7\u00bc\u00c2\u00cb\u00d1\u00de\u00e5\u00ec\u00f3\u00fa\u00ff"+
		"\u010e\u0115\u011a\u011f\u0123\u0127\u012b\u012e\u0132\u0136\u013a\u013e"+
		"\u014c\u0153\u0157\u015b\u0162\u0167\u0177\u017e\u0183\u018a\u0191\u0198"+
		"\u01a7\u01a9\u01ad\u01b7\u01c3\u01c9\u01d8\u01f1\u020d\u0220\u0227\u0231"+
		"\u0236\u023b\u0250\u0257\u025c\u0274\u027b\u0281\u0286\u028c\u0290\u0295"+
		"\u029b\u02a3\u02aa\u02af\u02c1\u02c8\u02cd\u02d5\u02de\u02e5\u02ed\u02f5"+
		"\u02fe\u0305\u030a\20\3\5\2\3\6\3\3\7\4\3\b\5\3\f\6\3\r\7\3\20\b\3\21"+
		"\t\3\32\n\3\33\13\3\35\f\3\36\r\3!\16\3\"\17";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}