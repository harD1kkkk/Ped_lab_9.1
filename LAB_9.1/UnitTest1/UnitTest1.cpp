#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_9.1/lab_9.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(StudentUnitTests)
    {
   public:
        TEST_METHOD(TestCreateStudent)
        {
            Student s;
            s.surname = "TestName";
            s.course = 2;
            s.specialty = "Math";
            s.o.physics = 4.5;
            s.o.math = 3.7;
            s.o.informatics = 5.0;

            Assert::AreEqual(string("TestName"), s.surname);
            Assert::AreEqual(2, s.course);
            Assert::AreEqual(string("Math"), s.specialty);
            Assert::AreEqual(4.5, s.o.physics);
            Assert::AreEqual(3.7, s.o.math);
            Assert::AreEqual(5.0, s.o.informatics);
        }

        TEST_METHOD(TestCountHighGradeStudents)
        {
            Student students[3] = {
                {"Alice", 1, "CS", {5.0, 4.8, 4.7}},
                {"Bob", 2, "Math", {3.5, 3.2, 4.0}},
                {"Charlie", 3, "Physics", {4.9, 4.6, 4.8}}
            };

            double result = CountHighGradeStudents(students, 3);
            Assert::AreEqual(66.67, result, 0.01);
        }

        TEST_METHOD(TestSortStudentsByCourse)
        {
            Student students[3] = {
                {"Alice", 3, "CS", {5.0, 4.8, 4.7}},
                {"Bob", 1, "Math", {3.5, 3.2, 4.0}},
                {"Charlie", 2, "Physics", {4.9, 4.6, 4.8}}
            };

            Sort(students, 3);

            Assert::AreEqual(1, students[0].course);
            Assert::AreEqual(2, students[1].course);
            Assert::AreEqual(3, students[2].course);
        }
    };
}
