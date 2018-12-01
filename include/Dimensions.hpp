/**
 * Copyright 2018, Niket Shah
 *
 *Copyright (c) 2018 Niket Shah

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */
/**
 * @file Dimensions.hpp
 * @author Niket Shah
 * @copyright 2018 Niket Shah
 * @brief Header for Dimensions class
 */

#ifndef INCLUDE_DIMENSIONS_HPP_
#define INCLUDE_DIMENSIONS_HPP_

class Dimensions {
 public:
  // Vehicle length
  double length = 1;
  // Vehicle width
  double width = 1;
  /*
   * @brief Constructor for class Dimensions
   * @param double length: length of the vehicle
   * @param double width: width of the vehicle
   */
  Dimensions(double length, double width);

  /*
   * @brief Default destructor for class Dimensions
   */
  virtual ~Dimensions();
  /*
   * @brief virtual method to get length of the vehicle
   * @param none
   * @return double: length of the vehicle
   */
  virtual double getLength();
  /*
   * @brief virtual method to get width of the vehicle
   * @param none
   * @return double: width of the vehicle
   */
  virtual double getWidth();
};

#endif  // INCLUDE_DIMENSIONS_HPP_
