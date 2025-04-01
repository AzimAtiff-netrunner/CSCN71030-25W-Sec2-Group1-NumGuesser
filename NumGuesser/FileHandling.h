#pragma once

// Save best attempt count (lowest = best)
void save_high_score(int attempts);

// Load best attempt count
int load_high_score();

// Save score history to file
void save_score_history(int* history, int size);

// Load score history from file
void load_score_history(int* history, int size);
