from simpful import *

#   A simple fuzzy inference system for the tipping problem
#   Create a fuzzy system object
FS = FuzzySystem()

#   Define fuzzy sets and linguistic variables
A_1 = FuzzySet(function=Trapezoidal_MF(a=0, b=0, c=80/3, d=130/3), term="low")
A_2 = FuzzySet(function=Triangular_MF(a=94/3, b=149/3, c=68), term="middle")
A_3 = FuzzySet(function=Trapezoidal_MF(a=169/3, b=73, c=100, d=100), term="high")
FS.add_linguistic_variable("Money", LinguisticVariable(
    [A_1, A_2, A_3], concept="ProjectMoney", universe_of_discourse=[0, 100]))

B_1 = FuzzySet(function=Trapezoidal_MF(a=0, b=0, c=30, d=190/3), term="low")
B_2 = FuzzySet(function=Trapezoidal_MF(a=110/3, b=70, c=100, d=100), term="high")
FS.add_linguistic_variable("Manpower", LinguisticVariable(
    [B_1, B_2], concept="ProjectManpower", universe_of_discourse=[0, 100]))

C_1 = FuzzySet(function=Trapezoidal_MF(a=0, b=0, c=22.5, d=37.5), term="low")
C_2 = FuzzySet(function=Trapezoidal_MF(a=27, b=42, c=58, d=73), term="middle")
C_3 = FuzzySet(function=Trapezoidal_MF(a=62.5, b=77.5, c=100, d=100), term="high")
FS.add_linguistic_variable("Risk", LinguisticVariable(
    [C_1, C_2, C_3], concept="Risk", universe_of_discourse=[0, 100]
))

#   Define fuzzy rules
R1 = "IF (Money IS high) OR (Manpower IS low) THEN (Risk IS low)"
R2 = "IF (Money IS middle) AND (Manpower IS high) THEN (Risk IS middle)"
R3 = "IF (Money IS low) THEN (Risk IS high)"
FS.add_rules([R1, R2, R3])

#   Set antecedents values
FS.set_variable("Money", 35)
FS.set_variable("Manpower", 60)

#   Perform Mamdani inference and print output
print(FS.Mamdani_inference(["Risk"]))

#   Test
FS.set_variable("Money", 50)
FS.set_variable("Manpower", 0)
print(FS.Mamdani_inference(["Risk"]))

FS.set_variable("Money", 100)
FS.set_variable("Manpower", 0)
print(FS.Mamdani_inference(["Risk"]))

FS.set_variable("Money", 70)
FS.set_variable("Manpower", 30)
print(FS.Mamdani_inference(["Risk"]))

FS.set_variable("Money", 0)
FS.set_variable("Manpower", 100)
print(FS.Mamdani_inference(["Risk"]))

FS.set_variable("Money", 35)
FS.set_variable("Manpower", 60)
print(FS.Mamdani_inference(["Risk"]))