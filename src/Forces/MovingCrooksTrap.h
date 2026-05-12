/**
 * @file    MovingCrooksTrap.h
 * @date    18/oct/2014
 * @author  Flavio 
 *
 */

#ifndef MovingCrooksTrap_H_
#define MovingCrooksTrap_H_

#include "BaseForce.h"
#include <vector>

// Forward declaration for buffer file operations
void appendBufferToFile_MvTrap(const std::string& filename, number* force_buffer, number* extension_buffer, int step);

using namespace std;

class MovingCrooksTrap: public BaseForce {
public:
	MovingCrooksTrap();
	virtual ~MovingCrooksTrap() {
	}

	std::tuple<std::vector<int>, std::string> init(input_file &inp) override;

	virtual LR_vector value(llint step, LR_vector &pos);
	virtual number potential(llint step, LR_vector &pos);

	void* cuda_force;


	string _file_path;
	int _buffer_size;
	std::vector<float> _force_buffer;
	std::vector<float> _extension_buffer;
    bool saved_last_step;
    llint last_step;
	int _sum_steps;
};

#endif // MovingCrooksTrap_H
