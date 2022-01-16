#include "AllLibraries.h"
#include "Student.h"
#include "Group.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	
	/*Student student1;
	student1.Show();
	Student student2("Ivanov", "Ivan", "Ivanovich", { 11, 12, 2000 }, "Gaidara 22", { 11111111, 222222, 333 }, { 9, 9, 9 });
	student2.SetEvaluations({ 8, 8, 8 });
	student2.Show();*/

	//Student ax[5];
	Group spu;
	Student a("Ivanov", "Ivan", "Ivanovich", { 11, 12, 2000 }, "Gaidara 22", { 11111111, 222222, 333 }, 5, 9, 9 );
	//a.Show();
	Student b("Karataev", "Yurij");
	//b.Show();
	Student c("Grishchuk", "Dmitriy", "Ivanovich", { 11, 12, 2000 }, "Gaidara 22", { 11111111, 222222, 333 }, 5, 9, 9);
	Student d("Orlov", "Stanislav", "Ivanovich", { 11, 12, 2000 }, "Gaidara 22", { 11111111, 222222, 333 }, 5, 9, 9);
	spu.AddStudents(a);
	spu.AddStudents(b);
	spu.AddStudents(c);
	spu.AddStudents(d);
	spu.ShowAllStudents();


	//Sleep(1000);
	system("cls");
	Group dsu("DSU", "builders", 2, 6);
	dsu.Transfer(spu, dsu);
	cout << endl;
	dsu.ShowAllStudents();
	cout << endl;
	spu.ShowAllStudents();
	dsu.OnceExpulsion();
	cout << endl;
	dsu.ShowAllStudents();
	spu.ALotOfExpulsion();
	spu.ShowAllStudents();

	
	//Group ax(4);

	/*a = b;
	a.Show();
	b.Show();*/
	//ax.ShowAllStudents();
	//ax[2].Show();

	return 0;
}
