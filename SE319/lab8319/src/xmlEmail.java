// Generated from xmlEmail.g4 by ANTLR 4.5.3
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class xmlEmail extends Lexer {
	static { RuntimeMetaData.checkVersion("4.5.3", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		EMAIL=1, WS=2, EERROR=3;
	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"LOCAL", "DOMAIN", "END", "EMAIL", "WS", "EERROR"
	};

	private static final String[] _LITERAL_NAMES = {
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "EMAIL", "WS", "EERROR"
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


	public xmlEmail(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "xmlEmail.g4"; }

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

	public static final String _serializedATN =
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\2\5g\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\3\2\6\2\21\n\2\r\2\16\2\22\3\2"+
		"\5\2\26\n\2\3\3\6\3\31\n\3\r\3\16\3\32\3\3\5\3\36\n\3\3\4\6\4!\n\4\r\4"+
		"\16\4\"\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\6\5.\n\5\r\5\16\5/\3\5\3\5"+
		"\6\5\64\n\5\r\5\16\5\65\3\5\6\59\n\5\r\5\16\5:\3\5\3\5\3\5\3\5\3\5\3\5"+
		"\3\5\3\5\3\5\3\5\3\5\3\6\6\6I\n\6\r\6\16\6J\3\6\3\6\3\7\3\7\3\7\3\7\3"+
		"\7\3\7\3\7\3\7\3\7\7\7X\n\7\f\7\16\7[\13\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7"+
		"\3\7\3\7\3\7\3\7\3Y\2\b\3\2\5\2\7\2\t\3\13\4\r\5\3\2\5\13\2##&&(/\62="+
		"??C\\aac|\u0080\u0080\6\2//\62;C\\c|\5\2\13\f\17\17\"\"m\2\t\3\2\2\2\2"+
		"\13\3\2\2\2\2\r\3\2\2\2\3\20\3\2\2\2\5\30\3\2\2\2\7 \3\2\2\2\t$\3\2\2"+
		"\2\13H\3\2\2\2\rN\3\2\2\2\17\21\t\2\2\2\20\17\3\2\2\2\21\22\3\2\2\2\22"+
		"\20\3\2\2\2\22\23\3\2\2\2\23\25\3\2\2\2\24\26\7\60\2\2\25\24\3\2\2\2\25"+
		"\26\3\2\2\2\26\4\3\2\2\2\27\31\t\3\2\2\30\27\3\2\2\2\31\32\3\2\2\2\32"+
		"\30\3\2\2\2\32\33\3\2\2\2\33\35\3\2\2\2\34\36\7\60\2\2\35\34\3\2\2\2\35"+
		"\36\3\2\2\2\36\6\3\2\2\2\37!\t\3\2\2 \37\3\2\2\2!\"\3\2\2\2\" \3\2\2\2"+
		"\"#\3\2\2\2#\b\3\2\2\2$%\7>\2\2%&\7g\2\2&\'\7o\2\2\'(\7c\2\2()\7k\2\2"+
		")*\7n\2\2*+\7@\2\2+-\3\2\2\2,.\5\3\2\2-,\3\2\2\2./\3\2\2\2/-\3\2\2\2/"+
		"\60\3\2\2\2\60\61\3\2\2\2\61\63\7B\2\2\62\64\5\5\3\2\63\62\3\2\2\2\64"+
		"\65\3\2\2\2\65\63\3\2\2\2\65\66\3\2\2\2\668\3\2\2\2\679\5\7\4\28\67\3"+
		"\2\2\29:\3\2\2\2:8\3\2\2\2:;\3\2\2\2;<\3\2\2\2<=\7>\2\2=>\7\61\2\2>?\7"+
		"g\2\2?@\7o\2\2@A\7c\2\2AB\7k\2\2BC\7n\2\2CD\7@\2\2DE\3\2\2\2EF\b\5\2\2"+
		"F\n\3\2\2\2GI\t\4\2\2HG\3\2\2\2IJ\3\2\2\2JH\3\2\2\2JK\3\2\2\2KL\3\2\2"+
		"\2LM\b\6\3\2M\f\3\2\2\2NO\7>\2\2OP\7g\2\2PQ\7o\2\2QR\7c\2\2RS\7k\2\2S"+
		"T\7n\2\2TU\7@\2\2UY\3\2\2\2VX\13\2\2\2WV\3\2\2\2X[\3\2\2\2YZ\3\2\2\2Y"+
		"W\3\2\2\2Z\\\3\2\2\2[Y\3\2\2\2\\]\7>\2\2]^\7\61\2\2^_\7g\2\2_`\7o\2\2"+
		"`a\7c\2\2ab\7k\2\2bc\7n\2\2cd\7@\2\2de\3\2\2\2ef\b\7\4\2f\16\3\2\2\2\r"+
		"\2\22\25\32\35\"/\65:JY\5\3\5\2\3\6\3\3\7\4";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}