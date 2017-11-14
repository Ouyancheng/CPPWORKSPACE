/*
 * AVLTreeDefines.h
 *
 *  Created on: Sep 30, 2016
 *      Author: ouyan
 */

#ifndef AVLTREEDEFINES_H_
#define AVLTREEDEFINES_H_

//Related to the balance factors, but they are not used in this project.
#ifndef EH
#define EH 0
#endif //! EH
#ifndef LH
#define LH 1
#endif //! LH
#ifndef RH
#define RH -1
#endif //! RH

//The MAX and MIN "functions", very important!
#ifndef MAX
#define MAX(a, b) (((a)>(b))?(a):(b))
#endif //! MAX
#ifndef MIN
#define MIN(a, b) (((a)<(b))?(a):(b))
#endif //! MIN


#endif /* AVLTREEDEFINES_H_ */
