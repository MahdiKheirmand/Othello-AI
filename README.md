# Othello-AI
<br/>AI for Othello;
<br/>
<br/> You can see the project from beggining to the end <a href=https://github.com/erfanesfahanian1378/Othello-project >click here</a>;
<hr color=navy width=1000 align=“center”>
every place got a point & based on the board given, chooses the best place;
<br/>the board is given as:    Name-of-File.exe 00000000 00000000 00000000 00012000 00021000 00000000 00000000 00000000 (AI's colour);
<br/>0 : empty house   ;   1 : black   ;   2 : white 
<br/>
<br/>21-30 : value of each house;
<br/>51-60 : a FOR to check each house whether it's available or not; for this it's used a function called 'eligible' for empty houses.
<br/><big><big><big><big>74-97 Function eligible :</big></big></big></big>
<br/>This function continous a pattern; it goes from north-west to south-east for each hose; it countinous the houses to find a house with same piece on the board; once it's founded a[i][j] = 0 which means the house is available to put the piece, else a[i][j] = -1 which means the oposition;
<br/>
<br/><big><big><big><big>104-116 Function eligible :</big></big></big></big>
<br/>This fuction chooses the house with the highest value of available houses;
<br/>
<br/><big><big><big><big>118-129 Function strategy :</big></big></big></big>
<br/>This fuction checks the available houses whith negative value using the fuction 'check' and if they are fixed(they cannot change the color) the valur becomes positive;
<br/>
<br/><big><big><big><big>131-198 Function check :</big></big></big></big>
<br/>This function continous a pattern; it goes from north-west to south-east for each hose; it countinous the houses checking if they are not oposition (fixed);
