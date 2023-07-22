using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BirdScript : MonoBehaviour
{
    public Rigidbody2D myRigidBody;
    public float flapStrength;
    public LogicScript logic;
    public bool isBirdAlive = true;
    public float upperDeathPosition = 17;
    public float lowerDeathPosition = -17;

    // Start is called before the first frame update
    void Start()
    {
        logic = GameObject.FindGameObjectWithTag("Logic").GetComponent<LogicScript>();
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.Space) && isBirdAlive)
        {
            myRigidBody.velocity = Vector2.up * flapStrength;
        }

        if(transform.position.y > upperDeathPosition ||  transform.position.y < lowerDeathPosition)
        {
            logic.GameOver();
            isBirdAlive = false;
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        logic.GameOver();
        isBirdAlive = false;
    }
}
