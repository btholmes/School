// Generated from xmlContent.g4 by ANTLR 4.5.3
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class xmlContent extends Lexer {
	static { RuntimeMetaData.checkVersion("4.5.3", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		EMAIL=1, WS=2, EERROR=3, DATE=4, DERROR=5, PHONE=6, PERROR=7, CREDIT=8, 
		CERROR=9, ADDRESS=10, AERROR=11, OTHER=12, OERROR=13;
	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"LOCAL", "DOMAIN", "END", "EMAIL", "WS", "EERROR", "DAY", "MONTH", "YEAR", 
		"DATE", "DERROR", "THREEDIGIT", "FOURDIGIT", "PHONE", "PERROR", "TWODIGIT", 
		"VISA", "MASTER", "AMERICAN", "DINERS", "JOINTVENTURE", "DISCOVER", "JCB", 
		"CREDIT", "CERROR", "FIVEDIGIT", "ADDRESS", "AERROR", "OTHERELEMENTNAME", 
		"ENDOTHERNAME", "OTHERELEMENTRULES", "OTHER", "OERROR"
	};

	private static final String[] _LITERAL_NAMES = {
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "EMAIL", "WS", "EERROR", "DATE", "DERROR", "PHONE", "PERROR", "CREDIT", 
		"CERROR", "ADDRESS", "AERROR", "OTHER", "OERROR"
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


	public xmlContent(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "xmlContent.g4"; }

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
			EERROR_action((RuleContext)_localctx, actionIndex);
			break;
		case 9:
			DATE_action((RuleContext)_localctx, actionIndex);
			break;
		case 10:
			DERROR_action((RuleContext)_localctx, actionIndex);
			break;
		case 13:
			PHONE_action((RuleContext)_localctx, actionIndex);
			break;
		case 14:
			PERROR_action((RuleContext)_localctx, actionIndex);
			break;
		case 23:
			CREDIT_action((RuleContext)_localctx, actionIndex);
			break;
		case 24:
			CERROR_action((RuleContext)_localctx, actionIndex);
			break;
		case 26:
			ADDRESS_action((RuleContext)_localctx, actionIndex);
			break;
		case 27:
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

			                 System.out.println("Found Email: " + getText().substring(7,getText().length()-8));
			             
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
	private void EERROR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 2:

			    System.out.println("Email error: " + getText());

			break;
		}
	}
	private void DATE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 3:

			    System.out.println("Found Date: " + getText().substring(6,getText().length()-7));

			break;
		}
	}
	private void DERROR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 4:

			    System.out.println("Date error: " + getText());

			break;
		}
	}
	private void PHONE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 5:

			    System.out.println("Found phone: " + getText().substring(7,getText().length()-8));

			break;
		}
	}
	private void PERROR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 6:

			    System.out.println("Phone error: " + getText());

			break;
		}
	}
	private void CREDIT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 7:

			    System.out.println("Found card: " + getText().substring(12,getText().length()-13));

			break;
		}
	}
	private void CERROR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 8:

			    System.out.println("Credit error: " + getText());

			break;
		}
	}
	private void ADDRESS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 9:

			    int start = getText().indexOf('>', 1) + 1;
			    int end = getText().indexOf('<', start);
			    System.out.println("Found address: " + getText().substring(start, end));

			break;
		}
	}
	private void AERROR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 10:

			    System.out.println("Address error: " + getText());

			break;
		}
	}
	private void OTHER_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 11:

			    int start = getText().indexOf('>') + 1;
			    int end = getText().indexOf('<', start);
			    String opening = getText().substring(1, start-1);
			    String ending = getText().substring(end+2, getText().length()-1);


			    if( opening.length() >= 3){
			     String xml = opening.substring(0,3);
			        if(Character.toLowerCase(xml.charAt(0)) == 'x' || Character.toLowerCase(xml.charAt(1)) == 'm' || Character.toLowerCase(xml.charAt(2)) == 'l'){
			            System.out.println("Can't start an element with XML: " + getText());
			        }else if(opening.equals(ending)){
			                  System.out.println("Found " + getText().substring(1, start-1) + " : " + getText().substring(start, end));
			        }else{
			                 System.out.println("Tags don't match: " + getText());
			        }
			    }else if(opening.equals(ending)){
			         System.out.println("Found " + getText().substring(1, start-1) + " : " + getText().substring(start, end));
			    }else{
			        System.out.println("Tags don't match: " + getText());
			    }



			break;
		}
	}
	private void OERROR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 12:

			    System.out.println("Element error: " + getText());

			break;
		}
	}

	public static final String _serializedATN =
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\2\17\u02d0\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31"+
		"\t\31\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t"+
		" \4!\t!\4\"\t\"\3\2\6\2G\n\2\r\2\16\2H\3\2\5\2L\n\2\3\3\6\3O\n\3\r\3\16"+
		"\3P\3\3\5\3T\n\3\3\4\6\4W\n\4\r\4\16\4X\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3"+
		"\5\3\5\6\5d\n\5\r\5\16\5e\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5"+
		"\3\5\3\5\3\5\3\6\6\6w\n\6\r\6\16\6x\3\6\3\6\3\7\3\7\3\7\3\7\3\7\3\7\3"+
		"\7\3\7\3\7\7\7\u0086\n\7\f\7\16\7\u0089\13\7\3\7\3\7\3\7\3\7\3\7\3\7\3"+
		"\7\3\7\3\7\3\7\3\7\3\b\7\b\u0097\n\b\f\b\16\b\u009a\13\b\3\b\3\b\3\b\3"+
		"\b\3\b\3\b\3\b\5\b\u00a3\n\b\3\t\7\t\u00a6\n\t\f\t\16\t\u00a9\13\t\3\t"+
		"\3\t\3\t\5\t\u00ae\n\t\3\n\3\n\3\n\3\n\3\n\6\n\u00b5\n\n\r\n\16\n\u00b6"+
		"\3\n\3\n\3\n\3\n\5\n\u00bd\n\n\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13"+
		"\3\13\7\13\u00c8\n\13\f\13\16\13\u00cb\13\13\3\13\3\13\7\13\u00cf\n\13"+
		"\f\13\16\13\u00d2\13\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3"+
		"\13\3\13\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\7\f\u00e7\n\f\f\f\16\f\u00ea"+
		"\13\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\r\5\r\u00f7\n\r\3\r\3"+
		"\r\5\r\u00fb\n\r\3\r\3\r\5\r\u00ff\n\r\3\r\3\r\5\r\u0103\n\r\3\16\5\16"+
		"\u0106\n\16\3\16\3\16\5\16\u010a\n\16\3\16\3\16\5\16\u010e\n\16\3\16\3"+
		"\16\5\16\u0112\n\16\3\16\3\16\5\16\u0116\n\16\3\17\3\17\3\17\3\17\3\17"+
		"\3\17\3\17\3\17\3\17\5\17\u0121\n\17\3\17\3\17\5\17\u0125\n\17\3\17\3"+
		"\17\3\17\3\17\3\17\3\17\3\17\3\17\3\17\3\17\3\17\3\17\3\17\3\20\3\20\3"+
		"\20\3\20\3\20\3\20\3\20\3\20\3\20\7\20\u013d\n\20\f\20\16\20\u0140\13"+
		"\20\3\20\3\20\3\20\3\20\3\20\3\20\3\20\3\20\3\20\3\20\3\20\3\21\5\21\u014e"+
		"\n\21\3\21\3\21\5\21\u0152\n\21\3\21\3\21\5\21\u0156\n\21\3\22\3\22\3"+
		"\22\3\22\3\22\3\22\3\22\3\22\3\22\3\22\3\22\3\22\5\22\u0164\n\22\5\22"+
		"\u0166\n\22\3\23\3\23\5\23\u016a\n\23\3\23\3\23\3\23\3\23\3\23\3\23\3"+
		"\24\3\24\5\24\u0174\n\24\3\24\3\24\3\24\3\24\3\24\3\24\3\25\3\25\3\25"+
		"\3\25\5\25\u0180\n\25\3\25\3\25\7\25\u0184\n\25\f\25\16\25\u0187\13\25"+
		"\3\25\3\25\3\25\3\25\3\25\3\25\3\25\3\25\3\25\3\25\3\25\3\25\5\25\u0195"+
		"\n\25\3\26\3\26\3\26\3\26\3\26\3\26\3\27\3\27\3\27\3\27\3\27\3\27\3\27"+
		"\3\27\3\27\3\27\3\27\3\27\3\27\3\27\3\27\3\27\3\27\5\27\u01ae\n\27\3\30"+
		"\3\30\3\30\3\30\3\30\3\30\3\30\3\30\3\30\3\30\3\30\3\30\3\30\3\30\3\30"+
		"\3\30\3\30\3\30\3\30\3\30\3\30\3\30\3\30\3\30\3\30\3\30\5\30\u01ca\n\30"+
		"\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31"+
		"\3\31\3\31\3\31\3\31\3\31\3\31\5\31\u01e0\n\31\3\31\3\31\3\31\3\31\3\31"+
		"\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\32\3\32\3\32"+
		"\3\32\3\32\3\32\3\32\3\32\3\32\3\32\3\32\3\32\3\32\3\32\7\32\u0200\n\32"+
		"\f\32\16\32\u0203\13\32\3\32\3\32\3\32\3\32\3\32\3\32\3\32\3\32\3\32\3"+
		"\32\3\32\3\32\3\32\3\32\3\32\3\32\3\33\3\33\3\33\3\33\3\33\3\33\3\34\3"+
		"\34\3\34\3\34\3\34\3\34\3\34\3\34\3\34\3\34\3\34\7\34\u0226\n\34\f\34"+
		"\16\34\u0229\13\34\3\34\6\34\u022c\n\34\r\34\16\34\u022d\3\34\7\34\u0231"+
		"\n\34\f\34\16\34\u0234\13\34\3\34\7\34\u0237\n\34\f\34\16\34\u023a\13"+
		"\34\3\34\5\34\u023d\n\34\3\34\6\34\u0240\n\34\r\34\16\34\u0241\3\34\3"+
		"\34\7\34\u0246\n\34\f\34\16\34\u0249\13\34\3\34\3\34\3\34\7\34\u024e\n"+
		"\34\f\34\16\34\u0251\13\34\3\34\3\34\3\34\3\34\3\34\3\34\3\34\3\34\3\34"+
		"\3\34\3\34\3\34\3\34\3\34\3\35\3\35\3\35\3\35\3\35\3\35\3\35\3\35\3\35"+
		"\3\35\3\35\7\35\u026c\n\35\f\35\16\35\u026f\13\35\3\35\3\35\3\35\3\35"+
		"\3\35\3\35\3\35\3\35\3\35\3\35\3\35\3\35\3\35\3\36\3\36\7\36\u0280\n\36"+
		"\f\36\16\36\u0283\13\36\3\36\3\36\3\37\3\37\3\37\3\37\7\37\u028b\n\37"+
		"\f\37\16\37\u028e\13\37\3\37\3\37\3 \7 \u0293\n \f \16 \u0296\13 \3!\3"+
		"!\3!\3!\3!\3\"\3\"\7\"\u029f\n\"\f\"\16\"\u02a2\13\"\3\"\3\"\7\"\u02a6"+
		"\n\"\f\"\16\"\u02a9\13\"\3\"\3\"\3\"\3\"\7\"\u02af\n\"\f\"\16\"\u02b2"+
		"\13\"\3\"\3\"\3\"\7\"\u02b7\n\"\f\"\16\"\u02ba\13\"\3\"\3\"\7\"\u02be"+
		"\n\"\f\"\16\"\u02c1\13\"\3\"\3\"\3\"\3\"\7\"\u02c7\n\"\f\"\16\"\u02ca"+
		"\13\"\3\"\5\"\u02cd\n\"\3\"\3\"\r\u0087\u00e8\u013e\u0201\u026d\u02a0"+
		"\u02a7\u02b0\u02b8\u02bf\u02c8\2#\3\2\5\2\7\2\t\3\13\4\r\5\17\2\21\2\23"+
		"\2\25\6\27\7\31\2\33\2\35\b\37\t!\2#\2%\2\'\2)\2+\2-\2/\2\61\n\63\13\65"+
		"\2\67\f9\r;\2=\2?\2A\16C\17\3\2\31\13\2##&&(/\62=??C\\aac|\u0080\u0080"+
		"\6\2//\62;C\\c|\5\2\13\f\17\17\"\"\3\2\62\62\3\2\63;\3\2\63\64\3\2\62"+
		";\3\2\63\63\3\2\62\64\3\2/\61\4\2\"\"/\60\3\2\63\67\4\2\66\6699\3\2\62"+
		"\67\3\2/\60\4\288::\3\2\"\"\b\2\"\"))//C\\aac|\3\2..\5\2\"\"C\\c|\3\2"+
		"C\\\7\2/\60\62;C\\aac|\13\2\"#&&(/\62=??C\\aac|\u0080\u0080\u0301\2\t"+
		"\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\35\3\2\2"+
		"\2\2\37\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\67\3\2\2\2\29\3\2\2\2\2A\3"+
		"\2\2\2\2C\3\2\2\2\3F\3\2\2\2\5N\3\2\2\2\7V\3\2\2\2\tZ\3\2\2\2\13v\3\2"+
		"\2\2\r|\3\2\2\2\17\u00a2\3\2\2\2\21\u00ad\3\2\2\2\23\u00bc\3\2\2\2\25"+
		"\u00be\3\2\2\2\27\u00de\3\2\2\2\31\u00f6\3\2\2\2\33\u0105\3\2\2\2\35\u0117"+
		"\3\2\2\2\37\u0133\3\2\2\2!\u014d\3\2\2\2#\u0165\3\2\2\2%\u0167\3\2\2\2"+
		"\'\u0171\3\2\2\2)\u0194\3\2\2\2+\u0196\3\2\2\2-\u01ad\3\2\2\2/\u01c9\3"+
		"\2\2\2\61\u01cb\3\2\2\2\63\u01f1\3\2\2\2\65\u0214\3\2\2\2\67\u021a\3\2"+
		"\2\29\u0260\3\2\2\2;\u027d\3\2\2\2=\u0286\3\2\2\2?\u0294\3\2\2\2A\u0297"+
		"\3\2\2\2C\u02cc\3\2\2\2EG\t\2\2\2FE\3\2\2\2GH\3\2\2\2HF\3\2\2\2HI\3\2"+
		"\2\2IK\3\2\2\2JL\7\60\2\2KJ\3\2\2\2KL\3\2\2\2L\4\3\2\2\2MO\t\3\2\2NM\3"+
		"\2\2\2OP\3\2\2\2PN\3\2\2\2PQ\3\2\2\2QS\3\2\2\2RT\7\60\2\2SR\3\2\2\2ST"+
		"\3\2\2\2T\6\3\2\2\2UW\t\3\2\2VU\3\2\2\2WX\3\2\2\2XV\3\2\2\2XY\3\2\2\2"+
		"Y\b\3\2\2\2Z[\7>\2\2[\\\7g\2\2\\]\7o\2\2]^\7c\2\2^_\7k\2\2_`\7n\2\2`a"+
		"\7@\2\2ac\3\2\2\2bd\5\3\2\2cb\3\2\2\2de\3\2\2\2ec\3\2\2\2ef\3\2\2\2fg"+
		"\3\2\2\2gh\7B\2\2hi\5\5\3\2ij\5\7\4\2jk\7>\2\2kl\7\61\2\2lm\7g\2\2mn\7"+
		"o\2\2no\7c\2\2op\7k\2\2pq\7n\2\2qr\7@\2\2rs\3\2\2\2st\b\5\2\2t\n\3\2\2"+
		"\2uw\t\4\2\2vu\3\2\2\2wx\3\2\2\2xv\3\2\2\2xy\3\2\2\2yz\3\2\2\2z{\b\6\3"+
		"\2{\f\3\2\2\2|}\7>\2\2}~\7g\2\2~\177\7o\2\2\177\u0080\7c\2\2\u0080\u0081"+
		"\7k\2\2\u0081\u0082\7n\2\2\u0082\u0083\7@\2\2\u0083\u0087\3\2\2\2\u0084"+
		"\u0086\13\2\2\2\u0085\u0084\3\2\2\2\u0086\u0089\3\2\2\2\u0087\u0088\3"+
		"\2\2\2\u0087\u0085\3\2\2\2\u0088\u008a\3\2\2\2\u0089\u0087\3\2\2\2\u008a"+
		"\u008b\7>\2\2\u008b\u008c\7\61\2\2\u008c\u008d\7g\2\2\u008d\u008e\7o\2"+
		"\2\u008e\u008f\7c\2\2\u008f\u0090\7k\2\2\u0090\u0091\7n\2\2\u0091\u0092"+
		"\7@\2\2\u0092\u0093\3\2\2\2\u0093\u0094\b\7\4\2\u0094\16\3\2\2\2\u0095"+
		"\u0097\t\5\2\2\u0096\u0095\3\2\2\2\u0097\u009a\3\2\2\2\u0098\u0096\3\2"+
		"\2\2\u0098\u0099\3\2\2\2\u0099\u009b\3\2\2\2\u009a\u0098\3\2\2\2\u009b"+
		"\u00a3\t\6\2\2\u009c\u009d\t\7\2\2\u009d\u00a3\t\b\2\2\u009e\u009f\7\65"+
		"\2\2\u009f\u00a3\7\62\2\2\u00a0\u00a1\7\65\2\2\u00a1\u00a3\7\63\2\2\u00a2"+
		"\u0098\3\2\2\2\u00a2\u009c\3\2\2\2\u00a2\u009e\3\2\2\2\u00a2\u00a0\3\2"+
		"\2\2\u00a3\20\3\2\2\2\u00a4\u00a6\t\5\2\2\u00a5\u00a4\3\2\2\2\u00a6\u00a9"+
		"\3\2\2\2\u00a7\u00a5\3\2\2\2\u00a7\u00a8\3\2\2\2\u00a8\u00aa\3\2\2\2\u00a9"+
		"\u00a7\3\2\2\2\u00aa\u00ae\t\6\2\2\u00ab\u00ac\t\t\2\2\u00ac\u00ae\t\n"+
		"\2\2\u00ad\u00a7\3\2\2\2\u00ad\u00ab\3\2\2\2\u00ae\22\3\2\2\2\u00af\u00b0"+
		"\7\64\2\2\u00b0\u00b1\7\62\2\2\u00b1\u00b2\3\2\2\2\u00b2\u00b3\t\b\2\2"+
		"\u00b3\u00b5\t\b\2\2\u00b4\u00af\3\2\2\2\u00b5\u00b6\3\2\2\2\u00b6\u00b4"+
		"\3\2\2\2\u00b6\u00b7\3\2\2\2\u00b7\u00bd\3\2\2\2\u00b8\u00b9\7\64\2\2"+
		"\u00b9\u00ba\7\63\2\2\u00ba\u00bb\7\62\2\2\u00bb\u00bd\7\62\2\2\u00bc"+
		"\u00b4\3\2\2\2\u00bc\u00b8\3\2\2\2\u00bd\24\3\2\2\2\u00be\u00bf\7>\2\2"+
		"\u00bf\u00c0\7f\2\2\u00c0\u00c1\7c\2\2\u00c1\u00c2\7v\2\2\u00c2\u00c3"+
		"\7g\2\2\u00c3\u00c4\7@\2\2\u00c4\u00c5\3\2\2\2\u00c5\u00c9\5\17\b\2\u00c6"+
		"\u00c8\t\13\2\2\u00c7\u00c6\3\2\2\2\u00c8\u00cb\3\2\2\2\u00c9\u00c7\3"+
		"\2\2\2\u00c9\u00ca\3\2\2\2\u00ca\u00cc\3\2\2\2\u00cb\u00c9\3\2\2\2\u00cc"+
		"\u00d0\5\21\t\2\u00cd\u00cf\t\13\2\2\u00ce\u00cd\3\2\2\2\u00cf\u00d2\3"+
		"\2\2\2\u00d0\u00ce\3\2\2\2\u00d0\u00d1\3\2\2\2\u00d1\u00d3\3\2\2\2\u00d2"+
		"\u00d0\3\2\2\2\u00d3\u00d4\5\23\n\2\u00d4\u00d5\7>\2\2\u00d5\u00d6\7\61"+
		"\2\2\u00d6\u00d7\7f\2\2\u00d7\u00d8\7c\2\2\u00d8\u00d9\7v\2\2\u00d9\u00da"+
		"\7g\2\2\u00da\u00db\7@\2\2\u00db\u00dc\3\2\2\2\u00dc\u00dd\b\13\5\2\u00dd"+
		"\26\3\2\2\2\u00de\u00df\7>\2\2\u00df\u00e0\7f\2\2\u00e0\u00e1\7c\2\2\u00e1"+
		"\u00e2\7v\2\2\u00e2\u00e3\7g\2\2\u00e3\u00e4\7@\2\2\u00e4\u00e8\3\2\2"+
		"\2\u00e5\u00e7\13\2\2\2\u00e6\u00e5\3\2\2\2\u00e7\u00ea\3\2\2\2\u00e8"+
		"\u00e9\3\2\2\2\u00e8\u00e6\3\2\2\2\u00e9\u00eb\3\2\2\2\u00ea\u00e8\3\2"+
		"\2\2\u00eb\u00ec\7>\2\2\u00ec\u00ed\7\61\2\2\u00ed\u00ee\7f\2\2\u00ee"+
		"\u00ef\7c\2\2\u00ef\u00f0\7v\2\2\u00f0\u00f1\7g\2\2\u00f1\u00f2\7@\2\2"+
		"\u00f2\u00f3\3\2\2\2\u00f3\u00f4\b\f\6\2\u00f4\30\3\2\2\2\u00f5\u00f7"+
		"\t\f\2\2\u00f6\u00f5\3\2\2\2\u00f6\u00f7\3\2\2\2\u00f7\u00f8\3\2\2\2\u00f8"+
		"\u00fa\t\b\2\2\u00f9\u00fb\t\f\2\2\u00fa\u00f9\3\2\2\2\u00fa\u00fb\3\2"+
		"\2\2\u00fb\u00fc\3\2\2\2\u00fc\u00fe\t\b\2\2\u00fd\u00ff\t\f\2\2\u00fe"+
		"\u00fd\3\2\2\2\u00fe\u00ff\3\2\2\2\u00ff\u0100\3\2\2\2\u0100\u0102\t\b"+
		"\2\2\u0101\u0103\t\f\2\2\u0102\u0101\3\2\2\2\u0102\u0103\3\2\2\2\u0103"+
		"\32\3\2\2\2\u0104\u0106\t\f\2\2\u0105\u0104\3\2\2\2\u0105\u0106\3\2\2"+
		"\2\u0106\u0107\3\2\2\2\u0107\u0109\t\b\2\2\u0108\u010a\t\f\2\2\u0109\u0108"+
		"\3\2\2\2\u0109\u010a\3\2\2\2\u010a\u010b\3\2\2\2\u010b\u010d\t\b\2\2\u010c"+
		"\u010e\t\f\2\2\u010d\u010c\3\2\2\2\u010d\u010e\3\2\2\2\u010e\u010f\3\2"+
		"\2\2\u010f\u0111\t\b\2\2\u0110\u0112\t\f\2\2\u0111\u0110\3\2\2\2\u0111"+
		"\u0112\3\2\2\2\u0112\u0113\3\2\2\2\u0113\u0115\t\b\2\2\u0114\u0116\t\f"+
		"\2\2\u0115\u0114\3\2\2\2\u0115\u0116\3\2\2\2\u0116\34\3\2\2\2\u0117\u0118"+
		"\7>\2\2\u0118\u0119\7r\2\2\u0119\u011a\7j\2\2\u011a\u011b\7q\2\2\u011b"+
		"\u011c\7p\2\2\u011c\u011d\7g\2\2\u011d\u011e\7@\2\2\u011e\u0120\3\2\2"+
		"\2\u011f\u0121\7*\2\2\u0120\u011f\3\2\2\2\u0120\u0121\3\2\2\2\u0121\u0122"+
		"\3\2\2\2\u0122\u0124\5\31\r\2\u0123\u0125\7+\2\2\u0124\u0123\3\2\2\2\u0124"+
		"\u0125\3\2\2\2\u0125\u0126\3\2\2\2\u0126\u0127\5\31\r\2\u0127\u0128\5"+
		"\33\16\2\u0128\u0129\7>\2\2\u0129\u012a\7\61\2\2\u012a\u012b\7r\2\2\u012b"+
		"\u012c\7j\2\2\u012c\u012d\7q\2\2\u012d\u012e\7p\2\2\u012e\u012f\7g\2\2"+
		"\u012f\u0130\7@\2\2\u0130\u0131\3\2\2\2\u0131\u0132\b\17\7\2\u0132\36"+
		"\3\2\2\2\u0133\u0134\7>\2\2\u0134\u0135\7r\2\2\u0135\u0136\7j\2\2\u0136"+
		"\u0137\7q\2\2\u0137\u0138\7p\2\2\u0138\u0139\7g\2\2\u0139\u013a\7@\2\2"+
		"\u013a\u013e\3\2\2\2\u013b\u013d\13\2\2\2\u013c\u013b\3\2\2\2\u013d\u0140"+
		"\3\2\2\2\u013e\u013f\3\2\2\2\u013e\u013c\3\2\2\2\u013f\u0141\3\2\2\2\u0140"+
		"\u013e\3\2\2\2\u0141\u0142\7>\2\2\u0142\u0143\7\61\2\2\u0143\u0144\7r"+
		"\2\2\u0144\u0145\7j\2\2\u0145\u0146\7q\2\2\u0146\u0147\7p\2\2\u0147\u0148"+
		"\7g\2\2\u0148\u0149\7@\2\2\u0149\u014a\3\2\2\2\u014a\u014b\b\20\b\2\u014b"+
		" \3\2\2\2\u014c\u014e\t\f\2\2\u014d\u014c\3\2\2\2\u014d\u014e\3\2\2\2"+
		"\u014e\u014f\3\2\2\2\u014f\u0151\t\b\2\2\u0150\u0152\t\f\2\2\u0151\u0150"+
		"\3\2\2\2\u0151\u0152\3\2\2\2\u0152\u0153\3\2\2\2\u0153\u0155\t\b\2\2\u0154"+
		"\u0156\t\f\2\2\u0155\u0154\3\2\2\2\u0155\u0156\3\2\2\2\u0156\"\3\2\2\2"+
		"\u0157\u0158\7\66\2\2\u0158\u0159\5\31\r\2\u0159\u015a\5\33\16\2\u015a"+
		"\u015b\5\33\16\2\u015b\u015c\5\33\16\2\u015c\u0166\3\2\2\2\u015d\u015e"+
		"\7\66\2\2\u015e\u015f\5\31\r\2\u015f\u0160\5\33\16\2\u0160\u0161\5\33"+
		"\16\2\u0161\u0163\t\b\2\2\u0162\u0164\t\f\2\2\u0163\u0162\3\2\2\2\u0163"+
		"\u0164\3\2\2\2\u0164\u0166\3\2\2\2\u0165\u0157\3\2\2\2\u0165\u015d\3\2"+
		"\2\2\u0166$\3\2\2\2\u0167\u0169\7\67\2\2\u0168\u016a\t\f\2\2\u0169\u0168"+
		"\3\2\2\2\u0169\u016a\3\2\2\2\u016a\u016b\3\2\2\2\u016b\u016c\t\r\2\2\u016c"+
		"\u016d\5!\21\2\u016d\u016e\5\33\16\2\u016e\u016f\5\33\16\2\u016f\u0170"+
		"\5\33\16\2\u0170&\3\2\2\2\u0171\u0173\7\65\2\2\u0172\u0174\t\f\2\2\u0173"+
		"\u0172\3\2\2\2\u0173\u0174\3\2\2\2\u0174\u0175\3\2\2\2\u0175\u0176\t\16"+
		"\2\2\u0176\u0177\5!\21\2\u0177\u0178\5\33\16\2\u0178\u0179\5\33\16\2\u0179"+
		"\u017a\5\31\r\2\u017a(\3\2\2\2\u017b\u017c\7\65\2\2\u017c\u017d\7\62\2"+
		"\2\u017d\u017f\3\2\2\2\u017e\u0180\t\f\2\2\u017f\u017e\3\2\2\2\u017f\u0180"+
		"\3\2\2\2\u0180\u0181\3\2\2\2\u0181\u0185\t\17\2\2\u0182\u0184\t\20\2\2"+
		"\u0183\u0182\3\2\2\2\u0184\u0187\3\2\2\2\u0185\u0183\3\2\2\2\u0185\u0186"+
		"\3\2\2\2\u0186\u0188\3\2\2\2\u0187\u0185\3\2\2\2\u0188\u0189\t\b\2\2\u0189"+
		"\u018a\5\33\16\2\u018a\u018b\5\33\16\2\u018b\u018c\5!\21\2\u018c\u0195"+
		"\3\2\2\2\u018d\u018e\7\65\2\2\u018e\u018f\t\21\2\2\u018f\u0190\5!\21\2"+
		"\u0190\u0191\5\33\16\2\u0191\u0192\5\33\16\2\u0192\u0193\5!\21\2\u0193"+
		"\u0195\3\2\2\2\u0194\u017b\3\2\2\2\u0194\u018d\3\2\2\2\u0195*\3\2\2\2"+
		"\u0196\u0197\7\67\2\2\u0197\u0198\5\31\r\2\u0198\u0199\5\33\16\2\u0199"+
		"\u019a\5\33\16\2\u019a\u019b\5\33\16\2\u019b,\3\2\2\2\u019c\u019d\78\2"+
		"\2\u019d\u019e\7\62\2\2\u019e\u019f\7\63\2\2\u019f\u01a0\7\63\2\2\u01a0"+
		"\u01a1\3\2\2\2\u01a1\u01a2\5\33\16\2\u01a2\u01a3\5\33\16\2\u01a3\u01a4"+
		"\5\33\16\2\u01a4\u01ae\3\2\2\2\u01a5\u01a6\78\2\2\u01a6\u01a7\7\67\2\2"+
		"\u01a7\u01a8\3\2\2\2\u01a8\u01a9\5!\21\2\u01a9\u01aa\5\33\16\2\u01aa\u01ab"+
		"\5\33\16\2\u01ab\u01ac\5\33\16\2\u01ac\u01ae\3\2\2\2\u01ad\u019c\3\2\2"+
		"\2\u01ad\u01a5\3\2\2\2\u01ae.\3\2\2\2\u01af\u01b0\7\64\2\2\u01b0\u01b1"+
		"\7\63\2\2\u01b1\u01b2\7\65\2\2\u01b2\u01b3\7\63\2\2\u01b3\u01b4\3\2\2"+
		"\2\u01b4\u01b5\5\33\16\2\u01b5\u01b6\5\33\16\2\u01b6\u01b7\5\31\r\2\u01b7"+
		"\u01ca\3\2\2\2\u01b8\u01b9\7\63\2\2\u01b9\u01ba\7:\2\2\u01ba\u01bb\7\62"+
		"\2\2\u01bb\u01bc\7\62\2\2\u01bc\u01bd\3\2\2\2\u01bd\u01be\5\33\16\2\u01be"+
		"\u01bf\5\33\16\2\u01bf\u01c0\5\31\r\2\u01c0\u01ca\3\2\2\2\u01c1\u01c2"+
		"\7\65\2\2\u01c2\u01c3\7\67\2\2\u01c3\u01c4\3\2\2\2\u01c4\u01c5\5!\21\2"+
		"\u01c5\u01c6\5\33\16\2\u01c6\u01c7\5\33\16\2\u01c7\u01c8\5\33\16\2\u01c8"+
		"\u01ca\3\2\2\2\u01c9\u01af\3\2\2\2\u01c9\u01b8\3\2\2\2\u01c9\u01c1\3\2"+
		"\2\2\u01ca\60\3\2\2\2\u01cb\u01cc\7>\2\2\u01cc\u01cd\7e\2\2\u01cd\u01ce"+
		"\7t\2\2\u01ce\u01cf\7g\2\2\u01cf\u01d0\7f\2\2\u01d0\u01d1\7k\2\2\u01d1"+
		"\u01d2\7v\2\2\u01d2\u01d3\7e\2\2\u01d3\u01d4\7c\2\2\u01d4\u01d5\7t\2\2"+
		"\u01d5\u01d6\7f\2\2\u01d6\u01d7\7@\2\2\u01d7\u01df\3\2\2\2\u01d8\u01e0"+
		"\5#\22\2\u01d9\u01e0\5%\23\2\u01da\u01e0\5\'\24\2\u01db\u01e0\5)\25\2"+
		"\u01dc\u01e0\5+\26\2\u01dd\u01e0\5-\27\2\u01de\u01e0\5/\30\2\u01df\u01d8"+
		"\3\2\2\2\u01df\u01d9\3\2\2\2\u01df\u01da\3\2\2\2\u01df\u01db\3\2\2\2\u01df"+
		"\u01dc\3\2\2\2\u01df\u01dd\3\2\2\2\u01df\u01de\3\2\2\2\u01e0\u01e1\3\2"+
		"\2\2\u01e1\u01e2\7>\2\2\u01e2\u01e3\7\61\2\2\u01e3\u01e4\7e\2\2\u01e4"+
		"\u01e5\7t\2\2\u01e5\u01e6\7g\2\2\u01e6\u01e7\7f\2\2\u01e7\u01e8\7k\2\2"+
		"\u01e8\u01e9\7v\2\2\u01e9\u01ea\7e\2\2\u01ea\u01eb\7c\2\2\u01eb\u01ec"+
		"\7t\2\2\u01ec\u01ed\7f\2\2\u01ed\u01ee\7@\2\2\u01ee\u01ef\3\2\2\2\u01ef"+
		"\u01f0\b\31\t\2\u01f0\62\3\2\2\2\u01f1\u01f2\7>\2\2\u01f2\u01f3\7e\2\2"+
		"\u01f3\u01f4\7t\2\2\u01f4\u01f5\7g\2\2\u01f5\u01f6\7f\2\2\u01f6\u01f7"+
		"\7k\2\2\u01f7\u01f8\7v\2\2\u01f8\u01f9\7e\2\2\u01f9\u01fa\7c\2\2\u01fa"+
		"\u01fb\7t\2\2\u01fb\u01fc\7f\2\2\u01fc\u01fd\7@\2\2\u01fd\u0201\3\2\2"+
		"\2\u01fe\u0200\13\2\2\2\u01ff\u01fe\3\2\2\2\u0200\u0203\3\2\2\2\u0201"+
		"\u0202\3\2\2\2\u0201\u01ff\3\2\2\2\u0202\u0204\3\2\2\2\u0203\u0201\3\2"+
		"\2\2\u0204\u0205\7>\2\2\u0205\u0206\7\61\2\2\u0206\u0207\7e\2\2\u0207"+
		"\u0208\7t\2\2\u0208\u0209\7g\2\2\u0209\u020a\7f\2\2\u020a\u020b\7k\2\2"+
		"\u020b\u020c\7v\2\2\u020c\u020d\7e\2\2\u020d\u020e\7c\2\2\u020e\u020f"+
		"\7t\2\2\u020f\u0210\7f\2\2\u0210\u0211\7@\2\2\u0211\u0212\3\2\2\2\u0212"+
		"\u0213\b\32\n\2\u0213\64\3\2\2\2\u0214\u0215\t\b\2\2\u0215\u0216\t\b\2"+
		"\2\u0216\u0217\t\b\2\2\u0217\u0218\t\b\2\2\u0218\u0219\t\b\2\2\u0219\66"+
		"\3\2\2\2\u021a\u021b\7>\2\2\u021b\u021c\7C\2\2\u021c\u021d\7f\2\2\u021d"+
		"\u021e\7f\2\2\u021e\u021f\7t\2\2\u021f\u0220\7g\2\2\u0220\u0221\7u\2\2"+
		"\u0221\u0222\7u\2\2\u0222\u0223\7@\2\2\u0223\u0227\3\2\2\2\u0224\u0226"+
		"\t\22\2\2\u0225\u0224\3\2\2\2\u0226\u0229\3\2\2\2\u0227\u0225\3\2\2\2"+
		"\u0227\u0228\3\2\2\2\u0228\u022b\3\2\2\2\u0229\u0227\3\2\2\2\u022a\u022c"+
		"\t\b\2\2\u022b\u022a\3\2\2\2\u022c\u022d\3\2\2\2\u022d\u022b\3\2\2\2\u022d"+
		"\u022e\3\2\2\2\u022e\u0232\3\2\2\2\u022f\u0231\t\22\2\2\u0230\u022f\3"+
		"\2\2\2\u0231\u0234\3\2\2\2\u0232\u0230\3\2\2\2\u0232\u0233\3\2\2\2\u0233"+
		"\u0238\3\2\2\2\u0234\u0232\3\2\2\2\u0235\u0237\t\23\2\2\u0236\u0235\3"+
		"\2\2\2\u0237\u023a\3\2\2\2\u0238\u0236\3\2\2\2\u0238\u0239\3\2\2\2\u0239"+
		"\u023c\3\2\2\2\u023a\u0238\3\2\2\2\u023b\u023d\t\24\2\2\u023c\u023b\3"+
		"\2\2\2\u023c\u023d\3\2\2\2\u023d\u023f\3\2\2\2\u023e\u0240\t\25\2\2\u023f"+
		"\u023e\3\2\2\2\u0240\u0241\3\2\2\2\u0241\u023f\3\2\2\2\u0241\u0242\3\2"+
		"\2\2\u0242\u0243\3\2\2\2\u0243\u0247\t\24\2\2\u0244\u0246\t\22\2\2\u0245"+
		"\u0244\3\2\2\2\u0246\u0249\3\2\2\2\u0247\u0245\3\2\2\2\u0247\u0248\3\2"+
		"\2\2\u0248\u024a\3\2\2\2\u0249\u0247\3\2\2\2\u024a\u024b\t\26\2\2\u024b"+
		"\u024f\t\26\2\2\u024c\u024e\t\22\2\2\u024d\u024c\3\2\2\2\u024e\u0251\3"+
		"\2\2\2\u024f\u024d\3\2\2\2\u024f\u0250\3\2\2\2\u0250\u0252\3\2\2\2\u0251"+
		"\u024f\3\2\2\2\u0252\u0253\5\65\33\2\u0253\u0254\7>\2\2\u0254\u0255\7"+
		"\61\2\2\u0255\u0256\7C\2\2\u0256\u0257\7f\2\2\u0257\u0258\7f\2\2\u0258"+
		"\u0259\7t\2\2\u0259\u025a\7g\2\2\u025a\u025b\7u\2\2\u025b\u025c\7u\2\2"+
		"\u025c\u025d\7@\2\2\u025d\u025e\3\2\2\2\u025e\u025f\b\34\13\2\u025f8\3"+
		"\2\2\2\u0260\u0261\7>\2\2\u0261\u0262\7C\2\2\u0262\u0263\7f\2\2\u0263"+
		"\u0264\7f\2\2\u0264\u0265\7t\2\2\u0265\u0266\7g\2\2\u0266\u0267\7u\2\2"+
		"\u0267\u0268\7u\2\2\u0268\u0269\7@\2\2\u0269\u026d\3\2\2\2\u026a\u026c"+
		"\13\2\2\2\u026b\u026a\3\2\2\2\u026c\u026f\3\2\2\2\u026d\u026e\3\2\2\2"+
		"\u026d\u026b\3\2\2\2\u026e\u0270\3\2\2\2\u026f\u026d\3\2\2\2\u0270\u0271"+
		"\7>\2\2\u0271\u0272\7\61\2\2\u0272\u0273\7C\2\2\u0273\u0274\7f\2\2\u0274"+
		"\u0275\7f\2\2\u0275\u0276\7t\2\2\u0276\u0277\7g\2\2\u0277\u0278\7u\2\2"+
		"\u0278\u0279\7u\2\2\u0279\u027a\7@\2\2\u027a\u027b\3\2\2\2\u027b\u027c"+
		"\b\35\f\2\u027c:\3\2\2\2\u027d\u0281\7>\2\2\u027e\u0280\t\27\2\2\u027f"+
		"\u027e\3\2\2\2\u0280\u0283\3\2\2\2\u0281\u027f\3\2\2\2\u0281\u0282\3\2"+
		"\2\2\u0282\u0284\3\2\2\2\u0283\u0281\3\2\2\2\u0284\u0285\7@\2\2\u0285"+
		"<\3\2\2\2\u0286\u0287\7>\2\2\u0287\u0288\7\61\2\2\u0288\u028c\3\2\2\2"+
		"\u0289\u028b\t\27\2\2\u028a\u0289\3\2\2\2\u028b\u028e\3\2\2\2\u028c\u028a"+
		"\3\2\2\2\u028c\u028d\3\2\2\2\u028d\u028f\3\2\2\2\u028e\u028c\3\2\2\2\u028f"+
		"\u0290\7@\2\2\u0290>\3\2\2\2\u0291\u0293\t\30\2\2\u0292\u0291\3\2\2\2"+
		"\u0293\u0296\3\2\2\2\u0294\u0292\3\2\2\2\u0294\u0295\3\2\2\2\u0295@\3"+
		"\2\2\2\u0296\u0294\3\2\2\2\u0297\u0298\5;\36\2\u0298\u0299\5? \2\u0299"+
		"\u029a\5=\37\2\u029a\u029b\b!\r\2\u029bB\3\2\2\2\u029c\u02a0\7>\2\2\u029d"+
		"\u029f\13\2\2\2\u029e\u029d\3\2\2\2\u029f\u02a2\3\2\2\2\u02a0\u02a1\3"+
		"\2\2\2\u02a0\u029e\3\2\2\2\u02a1\u02a3\3\2\2\2\u02a2\u02a0\3\2\2\2\u02a3"+
		"\u02a7\7@\2\2\u02a4\u02a6\13\2\2\2\u02a5\u02a4\3\2\2\2\u02a6\u02a9\3\2"+
		"\2\2\u02a7\u02a8\3\2\2\2\u02a7\u02a5\3\2\2\2\u02a8\u02aa\3\2\2\2\u02a9"+
		"\u02a7\3\2\2\2\u02aa\u02ab\7>\2\2\u02ab\u02ac\7\61\2\2\u02ac\u02b0\3\2"+
		"\2\2\u02ad\u02af\13\2\2\2\u02ae\u02ad\3\2\2\2\u02af\u02b2\3\2\2\2\u02b0"+
		"\u02b1\3\2\2\2\u02b0\u02ae\3\2\2\2\u02b1\u02b3\3\2\2\2\u02b2\u02b0\3\2"+
		"\2\2\u02b3\u02cd\7@\2\2\u02b4\u02b8\7>\2\2\u02b5\u02b7\13\2\2\2\u02b6"+
		"\u02b5\3\2\2\2\u02b7\u02ba\3\2\2\2\u02b8\u02b9\3\2\2\2\u02b8\u02b6\3\2"+
		"\2\2\u02b9\u02bb\3\2\2\2\u02ba\u02b8\3\2\2\2\u02bb\u02bf\7@\2\2\u02bc"+
		"\u02be\13\2\2\2\u02bd\u02bc\3\2\2\2\u02be\u02c1\3\2\2\2\u02bf\u02c0\3"+
		"\2\2\2\u02bf\u02bd\3\2\2\2\u02c0\u02c2\3\2\2\2\u02c1\u02bf\3\2\2\2\u02c2"+
		"\u02c3\7>\2\2\u02c3\u02c4\7\61\2\2\u02c4\u02c8\3\2\2\2\u02c5\u02c7\13"+
		"\2\2\2\u02c6\u02c5\3\2\2\2\u02c7\u02ca\3\2\2\2\u02c8\u02c9\3\2\2\2\u02c8"+
		"\u02c6\3\2\2\2\u02c9\u02cb\3\2\2\2\u02ca\u02c8\3\2\2\2\u02cb\u02cd\7@"+
		"\2\2\u02cc\u029c\3\2\2\2\u02cc\u02b4\3\2\2\2\u02cd\u02ce\3\2\2\2\u02ce"+
		"\u02cf\b\"\16\2\u02cfD\3\2\2\2A\2HKPSXex\u0087\u0098\u00a2\u00a7\u00ad"+
		"\u00b6\u00bc\u00c9\u00d0\u00e8\u00f6\u00fa\u00fe\u0102\u0105\u0109\u010d"+
		"\u0111\u0115\u0120\u0124\u013e\u014d\u0151\u0155\u0163\u0165\u0169\u0173"+
		"\u017f\u0185\u0194\u01ad\u01c9\u01df\u0201\u0227\u022d\u0232\u0238\u023c"+
		"\u0241\u0247\u024f\u026d\u0281\u028c\u0294\u02a0\u02a7\u02b0\u02b8\u02bf"+
		"\u02c8\u02cc\17\3\5\2\3\6\3\3\7\4\3\13\5\3\f\6\3\17\7\3\20\b\3\31\t\3"+
		"\32\n\3\34\13\3\35\f\3!\r\3\"\16";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}