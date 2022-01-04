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
	//Group a;
	//a.AddStudents(ax, 5);
	//a.ShowAllStudents();
	Group spu;
	Student a("Ivanov", "Ivan", "Ivanovich", { 11, 12, 2000 }, "Gaidara 22", { 11111111, 222222, 333 }, 9, 9, 9 );
	//a.Show();
	Student b("Karataev", "Yurij");
	Student c("Grishchuk", "Dmitriy");
	Student d("Orlov", "Stanislav");
	spu.AddStudents(a);
	spu.AddStudents(b);
	spu.AddStudents(c);
	spu.AddStudents(d);
	spu.ShowAllStudents();
	//Group ax(4);

	//a = b;
	//ax.ShowAllStudents();
	//ax[2].Show();

	return 0;
}
