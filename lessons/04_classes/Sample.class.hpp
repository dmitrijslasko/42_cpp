#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {

	public:

		Sample(void);
		Sample(int, int, int);

		~Sample(void);
		void print(void);
		
		void setAge(int);
		int getAge(void);
		
		void setKids(int);
		int getKids(void);

		void setShoeSize(int);
		int getShoeSize(void);

		static int	getPopulationSize(void);

	private:
		int _age;
		int _kids;
		int _shoe_size;
		static int _populationSize;
};

#endif