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
	Group a;
	a.ShowAllStudents();

	return 0;
}
