#Main sheets of Vim(while i dont pratice): Modes, sheets ands commands;

									FUNDAMENTALS/ BASICS	

esc : normal /navigate;
	:q : quit;
	:w : save;
	:wq : save and quit;
	:q! : force quit;
	:! : terminal commands;
	
	basic cursor: h, j, k, l;
	b : move to start of previous word; w : start of next word;
	e : move to the end of a word;
	0 : begin of a line;  $ : end of a line;
	gg : go to fist line of document ; G : to the last line;
	% : move between open and close brackets or parenteses;
	G<> : go to line number <>;
	zz : center
	
		
i : insert /text manipulation;
	i : insert before the cursor;  I : insert at start of the line;
	a : insert after the cursor;  A : insert at the end of the line;
	o : new line below;  O : new line above;
	d : delete;  dd : delete a line; D : deletes the line after the cursor;  dw : deletes a word;
	c : change (delete and enter insert);  cc : change a line; C : changes the line after the cursor;
	u : undo;  ctrl : redo;  ctrl + r : reundo;
	y : yank/copy; 	yy: copy the line;
	p : paste in the line below; P :above line
	r : replace a character
	ciw : change inner word;  diw : delete inner word;  ci<> : quote marks, parenteses, brackets;
	dt<>
	m <> : set a way point in the code;  press '<> to go to the waypoint;
	:%s/<>/<> : replace something for something else in the full file
	
		
v : visual; shift + v : visual line mode;  ctrl + v : visual block mode;
	
									INTER
	>>/ << : indent to right or left; = : auto indent the line;
	/ : search for something; n : jump to the next search; N : jump to the previous search;
	:reg : register;  delete -> copy
	
