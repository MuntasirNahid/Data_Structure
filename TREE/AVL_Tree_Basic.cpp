//right skewed tree or left skewed tree er vejal dur korar jonno AVl tree banano hoisey.
//An empty Binary tree is an AVL tree.
//height of left subtree and height of right subtree er parthokko 1 or -1 or 0 hoitey hobey.
// BF(balance factor)=h(l)-h(r)<=1
//shob gula node er balance factor er man -1,0,1 er moddhe ekta hoiley take balanced avl tree bola hoy..na hoiley takey unbalanced avl tree bola hoy
//insert korar shomoy bar bar rotation korey balance kore nitey hobey.
//AVL Tree always stays in a balanced shape.that's why it always maintains a (LOG N ) complexity.
//Rotation gula boi theke or google theke ekbar dekhe nilei hobey.

//Deletion:
//R0,R1,R-1,L0,L1,L-1;
//Char=j pashe delete hocche , digit hocche je pashe delete tar opposite side er subtree er root er BF.
//R0=Right subtree side theke delete,thik tar opposite pasher subtree(left subtree)er root er bf =0 .R0..and so on. 
//R1,R-1,L0,L1,L-1;

// delete er por Bf check korey ekta rotation korbo and bf er man stable obosthay niye eshe balanced subtree banaya dibo.

//rotation gula boi or google theke..

//implementation bishal boro.

