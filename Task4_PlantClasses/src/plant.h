#ifndef TASK4_PLANT_H
#define TASK4_PLANT_H

#include <string>

class Plant {
	public:
		
		Plant(const std::string& name, double growth_rate, float root_length, const std::string& leaf_color, float seed_diameter);
		
		// t = time plant grows
		virtual double CalculateHeight(double t) const = 0;
		
		void DisplayInfo() const;

		// getters
		std::string name() const;
		double growth_rate() const;
		float root_length() const;
		std::string leaf_color() const;
		float seed_diameter() const; 

		// virtual destructor
		virtual ~Plant() = default;

	private:
		std::string name_;
		double growth_rate_;
		float root_length_;
		std::string leaf_color_;
		float seed_diameter_;
};

#endif // TASK_PLANT_H
