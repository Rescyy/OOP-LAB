const int
HungerFromCarrots = 2,
ironForProduct = 5,
stoneForCement = 1,

carrotProducedPerPerson = 1,
ironProducedPerPerson = 1,
productProducedPerPerson = 1,
cementProducedPerPerson = 1,
stoneProducedPerPerson = 2,
prisonersSentPerKGB = 1,
studentsTaughtPerTeacher = 5,

maxLazy = 10,
LazyThreshold = 10,
maxUnrest = 10,
UnrestThreshold = 10,
maxHunger = 10,
HungerThreshold = 10,

pardonHungerThreshold = 0,
unrestHungerThreshold = 5,
lazyExecutionLimit = 7,

carrotProductionIntensity = 10,
ironProductionIntensity = 10,
productProductionIntensity = 10,
cementProductionIntensity = 10,
stoneProductionIntensity = 20,
learningIntensity = 5,

ageForSchool = 7,
ageForGraduation = 18,

chanceForColhoz = 55,
chanceForFabrica = 25,
chanceForGuard = 3,
chanceForTeacher = 10,
chanceForKGB = 3,

initialPopulation = 10,
initialCarrots = 10
;

const float

chanceInfantDeath = 1,
chanceAgeDeath = 0.1F,

productApartament = 1,
cementApartament = 1,
apartamentCostBase = 1.5F

;

int
maxPeople = 2*initialPopulation,
totalPeople = initialPopulation,
tot = chanceForColhoz +
chanceForFabrica +
chanceForGuard +
chanceForTeacher +
chanceForKGB,
unrestLimitToGulag = 15,
lazyLimitToGulag = 15
;

float
carrots = initialCarrots,
iron = 0,
stone = 0,
cement = 0,
product = 0
;