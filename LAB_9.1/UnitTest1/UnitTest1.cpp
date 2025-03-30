#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_9.1/lab_9.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(StudentUnitTests)
    {
    public:
        TEST_METHOD(TestStudentAverage)
        {
            Student s = { "Doe", 2, "Computer Science", 5.0, 4.0, 3.0 };
            double avg = studentAverage(s);
            Assert::AreEqual(4.0, avg, 0.001, L"Average grade should be 4.0");
        }

        TEST_METHOD(TestCountHighAverage)
        {
            Student students[3] = {
                { "Doe", 2, "CS", 5.0, 4.0, 3.0 },    
                { "Smith", 3, "Math", 5.0, 5.0, 5.0 },   
                { "Brown", 1, "Physics", 4.0, 4.0, 4.0 } 
            };
            int count = countHighAverage(students, 3, 4.5);
            Assert::AreEqual(1, count, L"Only one student has an average > 4.5");
        }

        TEST_METHOD(TestSubjectAverages)
        {
            Student students[3] = {
                { "Doe", 2, "CS", 5.0, 4.0, 3.0 },
                { "Smith", 3, "Math", 5.0, 5.0, 5.0 },
                { "Brown", 1, "Physics", 4.0, 4.0, 4.0 }
            };
            double avgPhysics, avgMath, avgInformatics;
            computeSubjectAverages(students, 3, avgPhysics, avgMath, avgInformatics);
            Assert::AreEqual((5.0 + 5.0 + 4.0) / 3.0, avgPhysics, 0.001, L"Incorrect average for Physics");
            Assert::AreEqual((4.0 + 5.0 + 4.0) / 3.0, avgMath, 0.001, L"Incorrect average for Math");
            Assert::AreEqual((3.0 + 5.0 + 4.0) / 3.0, avgInformatics, 0.001, L"Incorrect average for Informatics");
        }
    };
}
