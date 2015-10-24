struct sudoko{
	unsigned int a[10][10];
	unsigned int b[10][10];
	unsigned int c[10][10];
	int ra, ca, va;
	int rc, cc, vc;
}sudoko;
int t[10][10];
int insert();
int removes();
int printsudoko();
int exits();
int generate();
int check();
int solve();
int answer1();
int answer2();
int sudoprint();
int easy();
int medium();
int hard();
int checkcomp();

