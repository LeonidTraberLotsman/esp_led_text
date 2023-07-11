








String lett(char letter) {
	String res =
		(String)"" +
		"     " +
		"     " +
		"     " +
		"     " +
		"     " +
		"     " +
		"     " +
		"     ";
	if (letter == 'а' || letter == 'a' || letter == 'A' || letter == 'А') {
		res =
			(String)"" +
			"  +  " +
			" + + " +
			"+   +" +
			"+   +" +
			"+++++" +
			"+   +" +
			"+   +" +
			"     ";
	}
	
	if (letter == 'б' || letter == 'Б') {
		res =
			(String)"" +
			"+++++" +
			"+    " +
			"+    " +
			"+++++" +
			"+   +" +
			"+   +" +
			"+++++" +
			"     ";
	}
	if (letter == 'в' || letter == 'В' || letter == 'B') {
		res =
			(String)"" +
			"+++  " +
			"+  + " +
			"+  + " +
			"++++ " +
			"+   +" +
			"+   +" +
			"++++ " +
			"     ";
	}
	if (letter == 'г' || letter == 'Г') {
		res =
			(String)"" +
			"+++++" +
			"+    " +
			"+    " +
			"+    " +
			"+    " +
			"+    " +
			"+    " +
			"     ";
	}
	if (letter == 'д' || letter == 'Д') {
		res =
			(String)"" +
			"+++  " +
			"+  + " +
			"+  + " +
			"+  + " +
			"+   +" +
			"+++++" +
			"+   +" +
			"     ";
	}


	return res;
}