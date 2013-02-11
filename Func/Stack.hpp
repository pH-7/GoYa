/*
 *               PH GoYa - Programming Language
 *
 * Author: Pierre-Henry Soria <ph7software@gmail.com>
 * Copyright: (c) 2013, Pierre-Henry Soria. All Rights Reserved.
 *
 * For the full copyright and license information, please view the PH_GOYA_LICENSE.txt and PH_GOYA_COPYRIGHT.txt
 * file that was distributed with this source code.
*/

#ifndef STACK_FUNC_H_INCLUDED
#define STACK_FUNC_H_INCLUDED

namespace Func
{

    class Stack
    {
        public:
        Stack() : v1(0), v2(0), v3(0) {}
        double v1, v2, v3;
    };

}

#endif // STACK_FUNC_H_INCLUDED
