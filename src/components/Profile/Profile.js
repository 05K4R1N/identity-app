import React, { useState } from 'react';
import Card from '../UI/Card/Card';
import { Row, Col } from 'react-bootstrap';

const PROFILE_DATA = [
    {
      "label":"Apellido(s)",
      "value":"Gamboa Acho"
    },
    {
      "label":"Nombre(s)",
      "value":"Oscar Rolando"
    },
    {
      "label":"Nacido(a)",
      "value":"05/11/1990",
    },
    {
      "label":"En",
      "value":"Cochabamba - Cercado - Cochabamba"
    },
    {
      "label":"Estado Civil",
      "value":"Soltero",
    },
    {
      "label":"Profesion",
      "value":"Ing. de Sistemas"
    },
    {
      "label":"Domicilio",
      "value":"C. Jordan Pje. Loa #316"
    }
];

const Profile = (props) => {
    const [dataProfile, setDataProfile] = useState(PROFILE_DATA);
    return(
        <Card className="profile">
            <Row className="justify-content-md-center">
                <Col xs lg="10">
                    test
                </Col>
            </Row>
        </Card>
    );
}

export default Profile;