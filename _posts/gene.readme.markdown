---
layout: post
title:  "기말고사  과제"
date:   2022-06-17 17:10:37 +0900
categories: jekyll update
---
# 유전 알고리즘
<유전 알고리즘은 생물체가 환경에 적응하면서 진화해가는 모습을 모방하여 최적해를 찾아내는 검색 방법이다. 유전 알고리즘을 정의하기 위해 몇가지 개념을 정의한다.
</br>
+ 염색체(chromosome) : 생물학적으로는 유전 물질을 담고있는 하나의 집합. 유전알고리즘에서는 하나의 해를 표현한다. 
</br>
+ 유전자(gene) : 염색체를 구성하는 하나의 요소로 하나의 유전정보를 나타낸다. 어떤 염색체[A,B,C,D]가 있다면 각각 A,B,C,D의 유전자가 있는 것 이다.
</br>
+ 자손(offspring) : 특정시간 t에ㅔ 존재했던 염색체들로부터 생성된  염색체를 t에 존재했던 염색체들의 자손이라고 한다. 자손은 이전 세대와 비슷한 유전 정보를 갖는다.

+ 적합도(fitness) : 어떠한 염색체가 갖고 있는 고유값으로써, 해당 문제에 대해 염색체가 표현하는 해가 얼마나 적합한지를 나타낸다. 
# 유전 알고리즘 구조
1) 초기 염색체의 집합 생성

2) 초기 염색체들에 대한 적합도 계산

3) 현재 염색체들로부터 자손들을 생성

4) 생성된 자손들의 적합도 계산

5) 종료 조건 판별

6) 종료 조건이 거짓인 경우, (3)으로 이동하여 반복

7) 종료 조건이 참인 경우, 알고리즘을 종료</br>

# 유전 알고리즘을 통한 회귀식 추정
<h2> 1)초기 염색체의 집합 생성</h2>

나이대별로 평균키를 가장 잘 나타내는 1차함수를 유전 알고리즘을 통해 찾는다고 가정해보자.
<img src="picture.jpg">
 
<h3>우선 1차함수 Y=aX + b 에서 a와b가 유전자가 되는것이고 a와b의 범위는 -∞ ~ ∞이다.</h3>
<h3> 임의의 a와b값으로 이루어진 염색체[a,b]로 이루어진 집합을 생성한다.</h3>

<h2> 2)초기 염색체의 적합도 계산</h2>
각각의 염색체에 대해 오류값이 얼마인지 계산을한다. 19세이하의 x값을 1, 20대의 x값을 2, 30대의 x값을 3,....라 하면 y값은 키를 나타낼것이다.</br>
각각의 염색체의 유전자에 저장된 a와b를 y=aX +b에 대입하여 실제 값과 비교한다. 오류값 = |(실제값)-(염색체에 저장된 값)|^2 라 가정하여 모든 x값의 오류값을 계산한다. 그러면 오류값이 제일 작은 염색체가 적합도가 가장 높은 염색체가 되는 것 이다.

<h2> 3)현재 염색체들로 자손 생성</h2>
2번 과정을 통해 적합도가 높은 일부 염색체를 선정한다. 그 후 염색체 두 개 를 임의로 지정하여 자손을 생성한다. 자손을 생성할때 돌연변이(mutaion)연산과 교차(crossover)연산이 사용된다.

+ <h3>교차연산(crossover) : 교차연산은 두 염색체의 유전정보가 교차되는 연산을 의미한다. 따라서 두 염색체의 유전자일부가 서로 합쳐지는 연산이다.
<img src="crossover.png"> 

+ <h3>돌연변이 연산(mutation) : 만약에 교차연산만 실행되어 자손이 생성된다면 ,유전 알고리즘은 지역 최적점에 도달하게 될 것이다. 유전 알고리즘에서는 지역 최적점에 빠지는 문제를 해결하기 위해 새롭게 생성된 염색체에 확률적으로 돌연변이가 발생하도록 한다. 일반적으로 0.1%, 0.05% 등의 아주 낮은 확률로 돌연변이가 발생하도록 설정한다.
<img src="mutation.png">
이렇게 생성된 자손들의 염색체 집합에 대해 2번 과정인 적합도를 계산하고 적합도가 높은 일부 염색체를 선정하여 또 자손을 만든다. 이 과정을 반복하면 돌연변이로 인해 지역 최적점에 빠지지 않고 오류의 최솟값을 찾아갈수있다.</br>

# 만약에 돌연변이 발생확률을 너무 높거나 낮게하면 어떻게 될까?
자손이 생성될때 돌연변이 확률을 설정하는 이유는 유전적 다양성을 부여하여 보다 정확한 최적해를 찾기위해서이다. 그러나 돌연변이 확률을 너무 높게하면 돌연변이가 자주 발생하게 되어 적합도가 높은 염색체를 선정하고 그 염색체로 자손을 만드는 과정이 의미가 떨어지게 되어 프로그램 실행시간이 길어지게 된다.</br>
반대로 돌여변이 확률을 너무 낮게하면 돌연변이가 잘 발생하지 않아 지역 최적점에 빠질수 있다.

# 소스코드
```
import java.util.Random;

//Main class
public class SimpleDemoGA {

    Population population = new Population();
    Individual fittest;
    Individual secondFittest;
    int generationCount = 0;

    public static void main(String[] args) {

        Random rn = new Random();

        SimpleDemoGA demo = new SimpleDemoGA();

        
        demo.population.initializePopulation(10);

        
        demo.population.calculateFitness();

        System.out.println("Generation: " + demo.generationCount + " Fittest: " + demo.population.fittest);

        
        while (demo.population.fittest < 5) {
            ++demo.generationCount;

            
            demo.selection();

            demo.crossover();

            
            if (rn.nextInt()%7 < 5) {
                demo.mutation();
            }

            
            demo.addFittestOffspring();

            
            demo.population.calculateFitness();

            System.out.println("Generation: " + demo.generationCount + " Fittest: " + demo.population.fittest);
        }

        System.out.println("\nSolution found in generation " + demo.generationCount);
        System.out.println("Fitness: "+demo.population.getFittest().fitness);
        System.out.print("Genes: ");
        for (int i = 0; i < 5; i++) {
            System.out.print(demo.population.getFittest().genes[i]);
        }

        System.out.println("");

    }

    
    void selection() {

        fittest = population.getFittest();

        secondFittest = population.getSecondFittest();
    }

    
    void crossover() {
        Random rn = new Random();

       
        int crossOverPoint = rn.nextInt(population.individuals[0].geneLength);

       
        for (int i = 0; i < crossOverPoint; i++) {
            int temp = fittest.genes[i];
            fittest.genes[i] = secondFittest.genes[i];
            secondFittest.genes[i] = temp;

        }

    }

    
    void mutation() {
        Random rn = new Random();
        int mutationPoint = rn.nextInt(population.individuals[0].geneLength);

        
        if (fittest.genes[mutationPoint] == 0) {
            fittest.genes[mutationPoint] = 1;
        } else {
            fittest.genes[mutationPoint] = 0;
        }

        mutationPoint = rn.nextInt(population.individuals[0].geneLength);

        if (secondFittest.genes[mutationPoint] == 0) {
            secondFittest.genes[mutationPoint] = 1;
        } else {
            secondFittest.genes[mutationPoint] = 0;
        }
    }

    
    Individual getFittestOffspring() {
        if (fittest.fitness > secondFittest.fitness) {
            return fittest;
        }
        return secondFittest;
    }

    void addFittestOffspring() {

        fittest.calcFitness();
        secondFittest.calcFitness();

  
        int leastFittestIndex = population.getLeastFittestIndex();

        population.individuals[leastFittestIndex] = getFittestOffspring();
    }

}


class Individual {

    int fitness = 0;
    int[] genes = new int[5];
    int geneLength = 5;

    public Individual() {
        Random rn = new Random();

        //Set genes randomly for each individual
        for (int i = 0; i < genes.length; i++) {
            genes[i] = Math.abs(rn.nextInt() % 2);
        }

        fitness = 0;
    }

    public void calcFitness() {

        fitness = 0;
        for (int i = 0; i < 5; i++) {
            if (genes[i] == 1) {
                ++fitness;
            }
        }
    }

}

class Population {

    int popSize = 10;
    Individual[] individuals = new Individual[10];
    int fittest = 0;

    public void initializePopulation(int size) {
        for (int i = 0; i < individuals.length; i++) {
            individuals[i] = new Individual();
        }
    }

    public Individual getFittest() {
        int maxFit = Integer.MIN_VALUE;
        int maxFitIndex = 0;
        for (int i = 0; i < individuals.length; i++) {
            if (maxFit <= individuals[i].fitness) {
                maxFit = individuals[i].fitness;
                maxFitIndex = i;
            }
        }
        fittest = individuals[maxFitIndex].fitness;
        return individuals[maxFitIndex];
    }

    public Individual getSecondFittest() {
        int maxFit1 = 0;
        int maxFit2 = 0;
        for (int i = 0; i < individuals.length; i++) {
            if (individuals[i].fitness > individuals[maxFit1].fitness) {
                maxFit2 = maxFit1;
                maxFit1 = i;
            } else if (individuals[i].fitness > individuals[maxFit2].fitness) {
                maxFit2 = i;
            }
        }
        return individuals[maxFit2];
    }

    public int getLeastFittestIndex() {
        int minFitVal = Integer.MAX_VALUE;
        int minFitIndex = 0;
        for (int i = 0; i < individuals.length; i++) {
            if (minFitVal >= individuals[i].fitness) {
                minFitVal = individuals[i].fitness;
                minFitIndex = i;
            }
        }
        return minFitIndex;
    }

    public void calculateFitness() {

        for (int i = 0; i < individuals.length; i++) {
            individuals[i].calcFitness();
        }
        getFittest();
    }

}
```
