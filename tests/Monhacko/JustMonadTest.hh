<?hh //partial

namespace Monhacko\Test;

use \PHPUnit_Framework_TestCase as TestCase;

use \Monhacko\JustMonad;

class JustMonadTest extends TestCase {
	
	public function testBasic () : void {
		
		$this->assertEquals(2, (new JustMonad(2))->value());
		$this->assertEquals("foobar", (new JustMonad("foobar"))->value());
		
		$result = (new JustMonad(2))->bind($x ==> $x * 2)
								->bind($x ==> $x * 3)
								->value();
				
		$this->assertEquals(12, $result);
	}
}